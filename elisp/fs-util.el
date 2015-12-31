;; Примеры работы с файловой системой на elisp

;; Список инклюдов в файле
(defvar include-list)
;; initialize
(setq include-list nil)

;; Читаем файл и получаем список строк в качестве результата
(defun include-read-lines (filePath)
  "Return list of lines of a file at filePath."
  (with-temp-buffer
    (insert-file-contents filePath)
    (split-string (buffer-string) "\n" t)))

;; Парсим файл и получаем списо инклюдов
(defun include-source-get-path (line)
  "Get #include content from file-buuffer. nil if line is not a directive"
  (if (string-match "#include[ \t]+" line)
      (let ((result ""))
        (setq result 
           (replace-regexp-in-string "[<>\"]" "" ;; remove <|>|" symbols from include argument 
              (replace-regexp-in-string "#include[ \t]+" "" line))) ;; remove #include prefix
        result)))
;;        (push result include-list))))

;; helper function (print)
(defun print-elements-recursively (list)
  "Print each element of LIST on a line of its own. Uses recursion."
  (when list                     ; do-again-test
    (print (car list))           ; body
    (print-elements-recursively  ; recursive call
     (cdr list))))               ; next-step-expression

;; set path to parsed file
(setq src-file-path  "/usr/home/rhexo/ydisk/proj/app-lib/MPL/mpl__views_and_iterator_adapters_1/include/view_example.hpp")

;; print list of source includes
(print-elements-recursively include-list)

;; complete list entries with system include paths. Before this declare variable : include-search-path
(setq include-search-path
      '("/usr/include/"                    ;; system/include support
        "/usr/local/include/"              ;; local/include support
        "/usr/include/c++/v1/"))           ;; c++ support

;; get list of competed paths of include entries
(defun include-source-get-complete-path (line)
  "Get completed file path of #include argument."
  (let ((include-path "")
        (file-path ""))
    ;; Get argument of include definition
    (setq include-path (include-source-get-path line))    
    (if (> (length include-path) 0)
        ;; argument is not nil. Try to complete file path
        (dolist (item include-search-path file-path)
          (if (file-exists-p (concat item include-path))
              ;; file existence check -> true
              (setq file-path (concat item include-path)))
          ))
    ;; return as result
    file-path))

(include-source-get-complete-path "#include    <boost/mpl/contains.hpp>")


(defun include-test ()
  (let ((include-path "boost/mpl/contains.hpp")
        (file-path ""))
    (dolist (item include-search-path file-path)      
      (if (file-exists-p (concat item include-path))
          ;;file existence check -> true          
          (setq file-path (concat item include-path))))
    file-path))

(include-test )

;; parse sources lines. Stays only substrings of #include derictive
(mapcar 'include-source-get-complete-path (include-read-lines src-file-path))


;; [\"\<][a-zA-Z\/\._-]*[\"\>]$
