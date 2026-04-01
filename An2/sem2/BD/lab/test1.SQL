SELECT pid, nume FROM profesor WHERE pozitie = 'DE' and datan > '01/01/1960' ORDER BY nume DESC;

SELECT p.nume, f.univid FROM profesor p
                JOIN facultate f
                ON p.fid = f.fid
                JOIN universitate u
                ON u.univid = f.univid

SELECT NVL(s.bursa, -1), f.tel FROM student s
                JOIN facultate f
                ON f.fid = s.fid

SELECT p.* FROM profesor p 
                JOIN curs c
                ON p.pid = c.pid
                JOIN contractitems ci
                ON ci.cid = c.cid
                JOIN sala s
                ON s.cods = c.sala
WHERE ci.na >= 5 and s.fno = 2

SELECT * from profesor WHERE nume LIKE '% S% %'
