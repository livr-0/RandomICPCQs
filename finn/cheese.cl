(declaim (optimize (speed 3)))

(defun split (delim seq) 
  (if (= (length seq) 0)
      nil
      (let ((pos (search delim seq)))
        (if pos
          (cons (subseq seq 0 pos)
                (split delim (subseq seq (+ pos (length delim)))))
          (list seq)))))

(defun clamp (x l h) (max l (min h x)))

(defun read-cheese-header ()
  (map 'list #'parse-integer (split " " (read-line))))

(defun holes (hdr) (first hdr))
(defun slices (hdr) (second hdr))

(defun read-holes (n)
  (loop repeat n collect
    (map 'list (lambda (n) (/ (coerce (parse-integer n) 'double-float) 1000)) (split " " (read-line)))))

(defun hole-r (hole) (first hole))
(defun hole-z (hole) (fourth hole))

(defun hole-volume (hole start end)
  (let* ((r (hole-r hole))
         (z (hole-z hole))
         (start (clamp (- start z) (- r) r))
         (end (clamp (- end z) (- r) r)))
    (if (= start end)
        0
        (* pi (- (* r r (- end start)) (/ (- (* end end end) (* start start start)) 3))))))

(defun cheese-volume (holes start end)
  (- (* 100 100 (- end start))
     (loop for hole in holes
           sum (hole-volume hole start end))))
  
(defun find-slice-rec (holes prev start end target)
  (let* ((guess (/ (+ start end) 2))
         (guess-val (cheese-volume holes prev guess)))
    (cond
      ((< (abs (- start end)) 1e-7) guess)
      ((< guess-val target) (find-slice-rec holes prev guess end target))
      (t (find-slice-rec holes prev start guess target)))))
  
(defun find-slice (holes prev target) (float (- (find-slice-rec holes prev prev 100 target) prev)))

(defun main ()
  (let* ((header (read-cheese-header))
         (slices (slices header))
         (holes (read-holes (holes header)))
         (total-volume (cheese-volume holes 0 100))
         (slice-volume (/ total-volume slices))
         (previous 0.0d0))
    (loop repeat slices do
      (let ((size (find-slice holes previous slice-volume)))
        (incf previous size)
        (format t "~f~%" size)))))
  
(main)
