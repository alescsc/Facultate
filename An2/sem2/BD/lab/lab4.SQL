--1
SELECT p.nume, p.pid, f.fid, f.nume, f.adr FROM profesor p JOIN facultate f ON p.fid = f.fid;

--2
SELECT c.titlu, c.h, s.cap FROM curs c JOIN sala s ON c.sala = s.cods WHERE c.h > 12;

--3 
SELECT c.cid, c.titlu, s.cods, s.fno FROM curs c JOIN sala s ON c.sala = s.cods WHERE s.fno = 1;

--4
SELECT s.sid, s.cnp, s.nume, c.cid, c.titlu, p.nume FROM student s JOIN contract co ON s.sid = co.sid JOIN contractitems ci ON co.cnr = ci.cnr JOIN curs c ON ci.cid = c.cid JOIN profesor p ON c.pid = p.pid WHERE trim(c.zi) = trim(convert(to_char(SYSDATE, 'Day', 'NLS_DATE_LANGUAGE = Romanian'),'US7ASCII'));

--5
SELECT DISTINCT s.nume, s.cnp, s.sid, c.titlu, c.fid FROM student s JOIN contract co ON s.sid = co.sid JOIN contractitems ci ON co.cnr = ci.cnr JOIN curs c ON ci.cid = c.cid WHERE ci.nf <= 8;

--6
SELECT c.cid, c.titlu, f.nume FROM curs c LEFT JOIN contractitems ci ON c.cid = ci.cid JOIN facultate f ON c.fid = f.fid WHERE ci.cid is NULL ORDER BY f.nume, c.titlu;

--7
SELECT DISTINCT s.sid, s.nume FROM student s JOIN contract co ON s.sid = co.sid ORDER BY substr(s.nume, instr(s.nume, ' ') + 1);

--8
SELECT DISTINCT s.sid, s.nume FROM student s JOIN contract co ON s.sid = co.sid JOIN contractitems ci ON co.cnr = ci.cnr JOIN curs c ON ci.cid = c.cid WHERE lower(trim(c.zi)) = 'luni';

--9
SELECT DISTINCT s.sid, s.nume, s.cnp FROM student s JOIN contract co ON s.sid = co.sid JOIN contractitems ci ON co.cnr = ci.cnr JOIN curs c ON ci.cid = c.cid JOIN sala sa ON c.sala = sa.cods WHERE sa.cap < 200 ORDER BY substr(s.cnp, 2, 2) DESC, s.nume;