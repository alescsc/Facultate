# SCALARE: >, <, >=, <=, =
# LISTA VALORI: IN, NOT IN, ANY, ALL
# MULTIMI: EXISTS, NOT EXISTS
# CORELATE: intre doua tabele diferite, uneori cu EXISTS si NOT EXISTS

#subinterogari
SELECT c.cid, c.titlu FROM Curs c  
WHERE c.zi = ANY (SELECT zi FROM Curs WHERE titlu = 'Fizica') AND (c.fid = 'AC' OR c.fid ='ET');

SELECT s.sid, s.nume FROM Student s
WHERE (s.fid = 'MEC') AND EXISTS(SELECT c.sid FROM Contract c WHERE s.sid = c.sid);

SELECT p.nume, p.datan FROM Profesor P
WHERE (p.fid = 'MEC' OR p.fid = 'AC') AND p.datan < (SELECT datan FROM Profesor WHERE nume = 'Raul Brad');

SELECT nume, sid FROM Student 
WHERE anstud = 1 AND fid NOT IN(SELECT fid FROM Profesor WHERE pid IN (SELECT pid FROM Curs WHERE titlu = 'Limbaje de programare'));

#media e in student
SELECT nume, medie FROM Student 
WHERE fid = 'AC' AND medie > (SELECT medie FROM Student WHERE nume = 'Emanuel Petrescu');

SELECT f.fid, f.nume FROM Facultate f
WHERE NOT EXISTS (SELECT 1 FROM Student s WHERE s.fid = f.fid AND s.medie < 5.5); #era media in student

#multimi
SELECT fid, nume FROM Facultate 
WHERE fid in (SELECT fid FROM Student WHERE adr LIKE '%,H%')
UNION
SELECT fid, nume FROM Facultate 
WHERE fid in(SELECT fid FROM Profesor WHERE grad in (SELECT gid FROM GradDidactic WHERE grad = 'prof'));

SELECT cid, au FROM Curs 
WHERE fid in(SELECT fid FROM Facultate WHERE nume = 'AC')
MINUS
SELECT cid, au FROM Curs
WHERE pid in(SELECT pid FROM Profesor WHERE grad in(SELECT gid FROM GradDidactic WHERE grad = 'conf'));

SELECT cid, au FROM Curs
WHERE pid in(SELECT pid FROM Profesor WHERE grad in(SELECT gid FROM GradDidactic WHERE grad = 'prof'));
MINUS
SELECT cid, au FROM Curs 
WHERE fid in(SELECT fid FROM Facultate WHERE nume = 'AC')

SELECT pid, fid FROM Profesor 
WHERE fid in(SELECT fid From Facultate) AND datan < '01/01/1980'
INTERSECT
SELECT pid, fid FROM Profesor 
WHERE grad not in(SELECT gid FROM GradDidactic WHERE grad = 'conf')


###
SELECT cnr FROM Contract
INTERSECT
SELECT cnr FROM ContractItems WHERE ne < 7
ORDER BY cnr;


SELECT s.cods FROM Sala s
  WHERE s.cods NOT IN(SELECT c.sala FROM Curs c 
      WHERE c.pid IN(SELECT p.pid FROM Profesor p 
          WHERE p.grad IN(SELECT g.gid FROM GradDidactic g 
              WHERE grad='p')))
ORDER BY s.cap;

SELECT s.sid, s.nume FROM Student s 
  WHERE s.datan=(SELECT MIN(s2.datan) FROM Student s2 
      WHERE s2.fid=s.fid)
ORDER BY s.datan;


SELECT f.fid, f.tel FROM Facultate f WHERE f.univid IN(SELECT u.univid FROM Universitate u 
    WHERE adr='Piata Victoriei nr.2,Timisoara')
ORDER BY f.nume;


SELECT cods FROM Sala 
MINUS
SELECT sala FROM Curs WHERE zi='joi' AND h>=18
ORDER BY cods;


SELECT ne, na FROM ContractItems WHERE cid IN(SELECT cid FROM Curs 
    WHERE titlu='Course 1AC nr. 47')
ORDER BY cnr DESC;


SELECT p1.pid, p1.anang FROM Profesor p1 WHERE datan=(SELECT MAX(p2.datan) FROM Profesor p2 
    WHERE p1.grad=p2.grad)
ORDER BY p1.nume;


SELECT sid, nume FROM Student 
  WHERE sid NOT IN(SELECT sid FROM Contract 
      WHERE cnr IN(SELECT cnr FROM ContractItems WHERE nf<7))
ORDER BY cnp;