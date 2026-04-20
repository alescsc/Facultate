--1

SELECT sid, nume, anstud, bursa FROM Student
           WHERE bursa = (SELECT MIN(bursa) FROM Student WHERE bursa > 0)
UNION
SELECT sid, nume, anstud, bursa FROM Student
           WHERE bursa = (SELECT MAX(bursa) FROM Student);

--2

SELECT f.fid, f.nume, f.adr FROM Facultate f
            JOIN Curs c ON f.fid = c.fid
            JOIN Sala s ON c.sala = s.cods
            WHERE s.fno = 1
INTERSECT
SELECT f.fid, f.nume, f.adr FROM Facultate f
            JOIN Curs c ON f.fid = c.fid
            JOIN Sala s ON c.sala = s.cods
            WHERE s.fno = 7;

--3
--a
SELECT cid FROM Curs
MINUS
SELECT cid from ContractItems;

--b
SELECT cid FROM Curs
WHERE cid NOT IN (SELECT cid FROM ContractItems WHERE cid IS NOT NULL);

--c
SELECT c.cid FROM Curs c
LEFT JOIN ContractItems ci on c.cid = ci.cid
WHERE ci.cid IS NULL;

--4
SELECT sid, nume, anstud, bursa FROM Student
        WHERE bursa = 0 OR bursa IS NULL
INTERSECT
SELECT s.sid, s.nume, s.anstud, s.bursa FROM Student s
        WHERE s.sid IN(
            SELECT c.sid FROM Contract c
            JOIN ContractItems ci ON c.cnr = ci.cnr
            JOIN Curs cr ON cr.cid = ci.cid
            WHERE cr.sala = 'A111'
        );

--5
SELECT s.sid, s.nume, s.anstud, s.bursa FROM Student s
        JOIN Facultate f ON s.fid = f.fid
        WHERE f.tel = '0256-403211'
MINUS
SELECT s.sid, s.nume, s.anstud, s.bursa FROM Student s
        JOIN Contract c ON s.sid = c.sid
        JOIN ContractItems ci ON c.cnr = ci.cnr
        JOIN Curs cr ON cr.cid = ci.cid
        JOIN Profesor p ON cr.pid = p.pid
        WHERE p.nume = 'Romina Clarisa Dinu';