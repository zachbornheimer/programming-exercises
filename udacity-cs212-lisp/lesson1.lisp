; By Z. Bornheimer
; Udacity CS 212
; Provided as is without Warranty

; About the class | squared sum
(defun ss (nums &optional val)
  (if
    (null nums)
    val
    (ss (rest nums) (if (null val) (* (first nums) (first nums)) (+ val (* (first nums) (first nums))) ))))

; Test code for ss function
(defun test-ss ()
  (if
    (and
      (and
        (and
          (and
            (eq (ss '(1 2 3 4 5)) '55)
            (eq (ss '(7)) '49))
          (eq (ss '(9)) '81))
        (eq (ss '(7 9 1 4)) '147))
      (eq (ss '(1 2 3) '10) '24))
    'SS-PASSED
    'SS-FAILED))
