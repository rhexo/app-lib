;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

(message "%s" 
         (helm :sources (helm-build-sync-source "test"
                          :candidates '(one two three)
                          :fuzzy-match t)
               :buffer "*helm test*")
         )
