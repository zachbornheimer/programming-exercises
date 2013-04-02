(defvar *copyright*
  "These solutions are for the book __Lisp__ by Winston and Horn, 3rd edition.  These solutions were written by Z. Bornheimer.  They are relased as is (warantee-less).")
(defvar *chapters* '(3 4 5))
(defvar *chapter3* '((1 exchange) (2 construct) (3 rotate-left) (4 rotate-right) (5 palindromize) (6 (f-to-c c-to-f))))
(defvar *chapter4* '((1 divisible-by-three) (2 palidnromep) (3 rightp) (5 abs-min-max) (6 not-or-and) (7 check-temperature)))
(defvar *chapter5* '(1 skip-first-n))

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

(defun abs-min-max (function-name arg1 &optional arg2)
  (when (equal function-name 'ABS)
    (absr arg1))
  (when (equal function-name 'MAX)
    (maxr arg1 arg2))
)

(defun absr (l)
  ;; This function is a wrapper for tail-recurse-abs
  ;; absr extends the functionality of abs using tail
  ;; recursion and type predicate identification.
  (tail-recurse-abs '() l))

(defun tail-recurse-abs (progress toabs)
  (if (and (listp toabs) (not (null toabs)))
    (let ((ftoabs (first toabs)))
      (when (and (numberp ftoabs) (< ftoabs 0))
        (setf ftoabs (* ftoabs -1)))
      (tail-recurse-abs (append progress (cons ftoabs '())) (rest toabs)))
  (and
    (when (atom toabs)
      (and
        (when (< toabs 0)
          (setf toabs (* toabs -1)))
        (setf progress toabs)))   
    progress)))

(defun maxr (&rest l)
  (if (null l) 
    'nil
    (tail-recurse-max 'nil l '())))

(defun tail-recurse-max (largest firstelement restelement)
  ; Atomic?  Do largest.
  (if (and (numberp firstelement) (not (null firstelement)))
    (and (if (null largest)
        (setf largest firstelement)
        (if (> firstelement largest)
          (setf largest firstelement)
          largest))
      ; Is there more to look through?  Do that.
      (if (not (null restelement))
        (tail-recurse-max largest (append restelement '()) '())
        largest))
    ; Non-Null and not an atom?  Must be a list:
    (if (and (not (atom firstelement)) (not (null firstelement)))
      ; First of the firstelement.  Cons Rest to the rest.  Recurse.
      (tail-recurse-max largest (first firstelement) (append (rest firstelement) restelement))
      (when (and (atom firstelement) (not (null firstelement)))
        (tail-recurse-max largest restelement '())))))

(defun not-or-and (func &rest args)
  (cond
    ((equal func 'not) (not-cond (first args)))
    ((equal func 'or) (or-cond args))
    ((equal func 'and) (and-cond args))))

(defun not-cond (arg)
  (cond
    (arg nil)
    (t t)))

(defun or-cond (args)
  (let*
    ( (arg1 (first args))
      (arg2 (first (rest args)))
      (arg3 (first (rest (rest args)))))
    (cond
      (arg1)
      (arg2)
      (t arg3))))

(defun and-cond (args)
  (let*
    ( (arg1 (first args))
      (arg2 (first (rest args)))
      (arg3 (first (rest (rest args)))))
    (cond
      ((not arg1) nil)
      ((not arg2) nil)
      (t arg3))))

(defun check-temperature (temp)
  (cond
    ((> temp 100) 'RIDICULOUSLY-HOT)
    ((< temp 0) 'RIDICULOUSLY-COLD)
    (t 'OK)))

(defun skip-first-n (num list)
  (cond
    ((zerop num) list)
    ((endp list) num)
    (t (skip-first-n (- num 1) (rest list)))))
