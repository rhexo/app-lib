;; ----------------------------------
;; loop example
;; define a list
(setq animals '(gazelle giraffe lion tiger))

;; define print list function 
(defun print-elements-of-list (list)
  "Print each element of LIST on a line of its own."
  (while list
    (print (car list))
    (setq list (cdr list))))

;; evaluate
(print-elements-of-list animals)

;; loop example with let
(defun triangle (number-of-rows)
  "Add up the number of pebbels in a triangle.
The first row has one pebble, the second row two pebbels,
the third row three pebbels, and so on. 
The argument is NUMBER-OF-ROWS."
  (let ((total 0)
        (row-number 1))
    (while (<= row-number number-of-rows)
      (setq total (+ total row-number))
      (setq row-number (1+ row-number)))
    total))

(triangle 3)

;; loop with dolist macro
(defun reverse-list-with-dolist (list)
  "Using dolist, reverse the order of LIST."
  (let (value)  ; make sure list starts empty
    (dolist (element list value)
      (setq value (cons element value )))))

(reverse-list-with-dolist animals)

;; loop with dotimes macro
(defun triangle-using-doitems (number-of-rows)
  "Using doitems, add up the number of pebbels in a triangle."
  (let ((total 0))   ; otherwise a total is a void variable
    (dotimes (number number-of-rows total)
      (setq total (+ total (1+ number))))))


(triangle-using-doitems 5)

;; loop with recursion
(defun print-elements-recursively (list)
  "Print each element of LIST on a line of its own. Uses recursion."
  (when list                     ; do-again-test
    (print (car list))           ; body
    (print-elements-recursively  ; recursive call
     (cdr list))))               ; next-step-expression

(print-elements-recursively animals)
