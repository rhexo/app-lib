;; Пример базовых возможностй elisp
;; Программы elisp созданы и символьных выражений (sexps)
(+ 2 2)
;; Выражение следует читать как "Add 2 to 2"

;; sexps расположены внутри скобок, в том числе и вложенные выражения
(+ 2 (+ 1 1))

;; Выражения описываются с использованием атомов или других выражений
;; В примере выше 1 и 2 это атомы. А (+2 (+ 1 1)) b (+ 1 1) это символьные выражения

;; при поддержке 'lisp-interaction-mode' имеется возможность вычислять выражения
;; для этого необходимо расположить курсор справа от последней закрывающей скобки выражения
;; и нажать комбинацию C-u C-x C-e
(+ 3 (+ 1 2))

;; C-x C-e выводит тот же результат в минибуфер

;; Для присвоения значения переменной будем использовать следующее выражение
(setq my-name "Bastien")  
;; C-x C-e => "Bastien" будет отображено в минибуфере

;; Вставим "Hello" на месте текущей позиции курсора
(insert "Hello!")
;; C-x C-e => "Hello!"

;; Мы можем добавлять большее кол-во аргументов в выражение insert. В том числе и переменные
(insert "Hello" ", I am " my-name)

;; Мы можем уобъединять выражения в функции
(defun hello (name) (insert "Hello " name))
;; C-x C-e => объявляемы выражение

;; Вызываем нашу функцию. в качестве параметра используем текстовую строку - "you"
(hello "you")
;; C-x C-e => "Hello you"
;; --------------------------------------------------------------------------
;; Для того, чтобы создано новый буфер в другом окне используем выражение

(switch-to-buffer-other-window "*test*")
;; C-x C-e => Экранбудет разделен на две части и курсор будет расположен в другом окне

;; Мы можем группировать несколько выражений в 'progn
(progn
  (switch-to-buffer-other-window "*text*")
  (hello "you"))
;; C-x C-e => Создаем новый буффер и добавляем в него текст, поученный как результат
;; вычисления функции hello

;; Полезным выражением будет очистка буфера
(progn
  (switch-to-buffer-other-window "*text*")
  (erase-buffer)
  (hello "you"))

;; А так же, если потребуется, мы можем вернуться обратно
(progn
  (switch-to-buffer-other-window "*text*")
  (erase-buffer)
  (hello "you!")
  (other-window 1))

;; Мы можем определить локальную переменню и ее значение испольуя оператор let
(let ((local-name "you!!"))
  (switch-to-buffer-other-window "*text*")
  (erase-buffer)
  (hello local-name)
  (other-window 1))
;; в этом случае нет надоности использовать 'progn, так как функцию 
;; объединения нескольких выражений делает let

;; -------------------------------------------------------------------------
;; Форматы строк

(format "Hello %s!\n" "visitor")
;; Здесь %s дескриптор описывающий положение строки "visited" передающейся так же в 
;; виде параметра в наше выражение

;; Необходимо переработать нашу функцию hello. В новом определение будем использовать 
;; format для вывода сообщения
(defun hello (name)
  (insert (format "Hello %s!\n" name)))

(hello "you")

;; еще одна функция которая использует let
(defun greeting (name)
  (let ((your-name "Bastien"))
    (insert (format "Hello %s!\n\nI am %s."
                    name       ; аргумент функции
                    your-name  ; локальная переменная, значение "Bastien" присвоено оператором let
                    ))))

;; Вычислим выражение
(greeting "you")

;; Некоторые функции могут быть интерактивными
(read-from-minibuffer "Enter your name: ")

;; перепишем функцию greeting c учетом введенного возможности ввода имени
(defun greeting (from-name)
  (let ((your-name (read-from-minibuffer "Enter your name: ")))
    (insert (format "Hello %s!\n\nI am %s." 
                    from-name
                    your-name 
                    ))))

(greeting "Bastien")

;; В завершении добавим вывод результата в буфер другого окна
(defun greeting (from-name)
  (let ((your-name (read-from-minibuffer "Enter your name: ")))
    (switch-to-buffer-other-window "*test*")
    (erase-buffer)
    (insert (format "Hello %s!\n\nI am %s." your-name from-name))
    (other-window 1)))

;; тестируем что получилось
(greeting "Bastien")

;; -------------------------------------------------------------------------------------
;; Lists

;; определим список имен
(setq list-of-names '("Sarah" "Chloe" "Mathilde"))

;; извлекаем первый элемент списка
(car list-of-names)

;; получаем хвост списка
(cdr list-of-names)

;; добавляем элемент в начало списка
(push "Stephanie" list-of-names)

;; ИНФОРМАЦИЯ: car, cdr сам список не изменяют, в отличии от push

;; организуем вызов функции hello для каждого элемента из списка
(mapcar 'hello list-of-names)

;; переработаем нашу функцию greeting чтобы поприветствовать всех из списка
(defun greeting ()
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  (mapcar 'hello list-of-names)
  (other-window 1))

(greeting)

;; теперь давайте немного пересмотрим то, чсодержимое буфера
(defun replace-hello-by-bonjour ()
  (switch-to-buffer-other-window "*test*")
  (goto-char (point-min))
  (while (search-forward "Hello")
    (replace-match "Bonjour"))
  (other-window 1))

;; (goto-char (point-min)) возвращает курсор в начало буфера
;; (search-forward "Hello") search for string "Hello"
;; (while x y) цикл, вычисляет y до тех пор пока x что-то возвращает
;; Если x возвращает 'nil (nothing), цикл завершается

(replace-hello-by-bonjour)

;; в процессе вычисления мы получаем ошибку "Search failed: Hello"
;; чтобы исправить ситуацию необходимо сказать search-forward когда нужно остановиться
;; и когда необходимо безмолвно завершить обработку с ошибкой, если поиск безрезультатен

;; (search-forward "Hello" nil t) вот этот трюк

;; nil - говорит, что поиск не связан с позицией
;; t - говорит, что нужно безмолвно завершить обработку, если ничего не найдено

(defun hello-to-bonjour ()
  (switch-to-buffer-other-window "*test*")
  (erase-buffer)
  ;; пишем приветствие для списка имен
  (mapcar 'hello list-of-names)
  (goto-char (point-min))
  ;; подменяем Hello на Bonjour
  (while (search-forward "Hello" nil t)
    (replace-match "Bonjour"))
  (other-window 1))

(hello-to-bonjour)

;; Раскрасим немного имена
(defun boldify-names ()
  (switch-to-buffer-other-window "*test*")
  (goto-char (point-min))
  (while (re-search-forward "Bonjour \\(.+\\)!" nil t)  
    (add-text-properties (match-beginning 1)
                         (match-end 1)
                         (list 'face 'bold)))
  (other-window 1))

;; используем регулярное выражение как шаблон для поиска
(boldify-names)
