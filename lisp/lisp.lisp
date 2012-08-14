(defvar *copyright*
  "These solutions are for the book __Lisp__ by Winston and Horn, 3rd edition.  These solutions were written by Z. Bornheimer.  They are relased as is (warantee-less).")
(defvar *chapters* '(3 4))
(defvar *chapter3* '((1 exchange) (2 construct) (3 rotate-left) (4 rotate-right) (5 palindromize) (6 (f-to-c c-to-f))))
(defvar *chapter4* '((1 divisible-by-three) (2 palidnromep) (3 rightp)))

(defun exchange (var)
  (list (first (last var)) (first var)))

(defun construct (atom-to-prepend list)
  (cons atom-to-prepend list))

(defun rotate-left (list)
  (reverse (cons (first list) (reverse (rest list)))))

(defun rotate-right (list)
  (cons (first (reverse (list))) (butlast list)))

(defun palindromize (list)
  (append list (reverse list)))

(defun f-to-c (degrees)
  (- (/ (* (+ degrees 40)  5)  9)  40))

(defun c-to-f (degrees)
  (- (/ (* (+ degrees 40) 9) 5)  40))

(defun divisible-by-three (dividend)
  (zerop (mod dividend 3)))

(defun palindromep (list)
  (equal list (reverse(list))))

(defun rightp (hyp side1 side2)
  (zerop (- (* hyp hyp) (+ (* side1 side1) (* side2 side2)))))