--CREATE DATABASE Airline
USE "9301-ERAhmetyanova"

������� ������������

CREATE TABLE s_airline	
	
   (airline_num	        NUMERIC(10) IDENTITY PRIMARY KEY,
    airline_name        VARCHAR(20) NOT NULL,
   );
   
������� �������

CREATE TABLE s_plane	
	
   (plane_num	      NUMERIC(10) IDENTITY PRIMARY KEY,
    plane_capacity    NUMERIC(35),
    plane_type        VARCHAR(50),
    airline_num	      NUMERIC(10),

CONSTRAINT fk_plane FOREIGN KEY (airline_num)
        REFERENCES s_airline (airline_num)
        );
        
������� ����������

CREATE TABLE s_timetable	
	
   (timetable_numofflight 	            NUMERIC(15) IDENTITY PRIMARY KEY,
    timetable_direction                 VARCHAR(100) NOT NULL,
    timetable_dayofdeparture	        DATETIME, 
    timetable_timeofdeparture    	    DATETIME,  
    timetable_timeofarrival             DATETIME,  
    timetable_runtime                   DATETIME,
   );
   
   ALTER TABLE s_timetable ADD timetable_arrival VARCHAR(100) NOT NULL

������� ����

CREATE TABLE s_flight		
   (flight_ID               NUMERIC(20) IDENTITY PRIMARY KEY,
    flight_timeofdeparture 	DATETIME,  
    flight_timeofarrival 	DATETIME,  
    flight_dayofdeparture	DATETIME, 
    flight_status           VARCHAR(50),
    timetable_numofflight 	NUMERIC(15),
    plane_num	            NUMERIC(10),

CONSTRAINT fk_flight_timetable_numofflight FOREIGN KEY (timetable_numofflight) 
    REFERENCES s_timetable (timetable_numofflight),
CONSTRAINT fk_flight_plane_num FOREIGN KEY (plane_num) 
	REFERENCES s_plane (plane_num)
	);

������� �����

CREATE TABLE s_bilet 		
   (bilet_num 	              NUMERIC(20) IDENTITY PRIMARY KEY,
    bilet_place               NUMERIC(30),
    bilet_class	              VARCHAR(80),
    bilet_price	              MONEY,
    passenger_num             NUMERIC(10),
    flight_ID                 NUMERIC(20),

CONSTRAINT fk_bilet_passenger_num FOREIGN KEY (passenger_num)
    REFERENCES s_passenger (passenger_num),
CONSTRAINT fk_bilet_flight_ID FOREIGN KEY (flight_ID) 
	REFERENCES s_flight (flight_ID),
CONSTRAINT ch_bilet_price  CHECK (bilet_price>0)
	);
	
������� �������� 

CREATE TABLE s_passenger 		
   (passenger_num           NUMERIC(10) IDENTITY PRIMARY KEY,
    passenger_name 	        VARCHAR(100) NOT NULL,
    passenger_priznak	    VARCHAR(80),
    passenger_path	        VARCHAR(30),
   );





������� ������������

INSERT INTO s_airline (airline_name) 
VALUES('Aeroflot');
INSERT INTO s_airline (airline_name) 
VALUES('UTair');
INSERT INTO s_airline (airline_name) 
VALUES('Ural');
INSERT INTO s_airline (airline_name) 
VALUES('S7');
INSERT INTO s_airline (airline_name) 
VALUES('Transaero');

DELETE FROM s_airline WHERE airline_num > 5;

INSERT INTO s_airline (airline_name) 
VALUES('Aurora');
INSERT INTO s_airline (airline_name) 
VALUES('Meridian');
INSERT INTO s_airline (airline_name) 
VALUES('Chartex');

SELECT * FROM s_airline;

������� �������

INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('BOEING 777-300', 33, 5);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('Airbus 320-210', 35, 2);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('��-204-100', 15, 4);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('Boeing 757-200', 21, 1);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('BOEING 747-400', 23, 3);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('IL9', 10, 1);

DELETE FROM s_plane WHERE plane_num > 28;

INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('Airbus A330', 11, 79);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('SSJ-95', 18, 80);
INSERT INTO s_plane (plane_type, plane_capacity, airline_num)
VALUES ('BOEING 737-500', 30, 78);

SELECT * FROM s_plane;

������� ����������

INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime) 
VALUES('������','������', '22-10-2014', '13:00', '15:20', '2:20');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('�����-���������', '�����', '25-10-2014', '14:50', '17:25', '2:35');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('�������', '�����-���������', '23-10-2014', '23:00', '04:10', '5:10');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('���������', '�������������', '23-10-2014', '12:00', '14:45', '2:45');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('���', '����', '24-10-2014', '10:20', '16:20', '6:00');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('���������', '������', '26-10-2014', '15:50', '17:35', '1:45');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('������', '������', '22-10-2014', '17:30', '19:00', '1:30');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('���������', '������', '25-10-2014', '14:00', '19:10', '5:10');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('������', '������', '24-10-2014', '17:10', '18:05', '0:55');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('�����-���������', '���������', '26-10-2014', '20:05', '20:45', '0:40');
INSERT INTO s_timetable (timetable_direction, timetable_arrival, timetable_dayofdeparture, timetable_timeofdeparture, timetable_timeofarrival, timetable_runtime)
VALUES('������������', '������', '23-10-2014', '11:50', '15:25', '3:35');

SELECT * FROM s_timetable;

������� ��������

INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('�������� ����� ����������', '��������', '������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('������� ���� ����������', '�������', '������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('��������� ������� ����������', '��������', '������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('�������� ������� ��������', '��������', '����');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('������ �������� ��������', '�������', '������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('������ ���� ��������', '��������', '�����');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('������ ����� �������', '��������', '����');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('������ ������ ����������', '��������', '������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('���������� ������� �������������', '��������', '�����-���������');
INSERT INTO s_passenger (passenger_name, passenger_priznak, passenger_path) 
VALUES('�������� ����� ����������', '��������', '�����');

DELETE FROM s_passenger WHERE passenger_num < 11;
DELETE FROM s_passenger WHERE passenger_num > 20;

SELECT * FROM s_passenger;

������� ����

INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('12:00','14:45','23-10-2014','�������� �������', 4, 26);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('17:30','19:00','22-10-2014','�������', 7, 83);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('14:00','19:10','25-10-2014','�������', 8, 24);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('20:05','20:45','26-10-2014','�������', 10, 28);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('17:10','18:05','24-10-2014','�������', 9, 27);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('13:00','15:20','22-10-2014','�������', 1, 23);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('15:50','17:35','26-10-2014','�������� �������', 6, 84);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('23:00','04:10','23-10-2014','�������', 3, 85);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('11:50','15:25','23-10-2014','�������', 11, 24);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('14:50','17:25','25-10-2014','�������', 2, 25);
INSERT INTO s_flight (flight_timeofdeparture, flight_timeofarrival, flight_dayofdeparture, flight_status, timetable_numofflight, plane_num)
VALUES ('10:20','16:20','24-10-2014','�������� �������', 5, 23);

SELECT * FROM s_flight;

������� �����

INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(2, '������', 2500, 11, 20);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(3, '������', 2000, 12, 20);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(28, '������', 10000, 18, 17);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(2, '������', 8500, 14, 12);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(4, '������', 15400, 17, 13);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(2, '������', 3400, 13, 15);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(15, '������', 6700, 16, 21);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(18, '������', 3200, 15, 16);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(30, '������', 1900, 20, 17);
INSERT INTO s_bilet (bilet_place, bilet_class, bilet_price, passenger_num, flight_ID) 
VALUES(7, '������', 3100, 19, 14);


SELECT * FROM s_bilet;


�������

SELECT plane_num, plane_type FROM s_plane
	WHERE plane_num IN
		(SELECT plane_num FROM s_flight
		WHERE flight_dayofdeparture = '23-10-2014')
		
SELECT passenger_num, passenger_name, passenger_path FROM s_passenger
	WHERE passenger_num IN
		(SELECT passenger_num FROM s_bilet
		WHERE bilet_class = '������')

SELECT bilet_class, bilet_price FROM s_bilet 
	WHERE bilet_price =  
		(SELECT MAX(bilet_price) FROM s_bilet)

SELECT timetable_numofflight, timetable_direction, timetable_arrival FROM s_timetable c
	WHERE EXISTS
		(SELECT * FROM s_flight b
		WHERE flight_timeofdeparture 	
BETWEEN '12:00' AND '20:00'
AND c.timetable_numofflight=b.timetable_numofflight)

SELECT airline_num, airline_name FROM s_airline c
	WHERE EXISTS
		(SELECT * FROM s_plane b
		WHERE plane_capacity 	
BETWEEN 15 AND 30
AND c.airline_num=b.airline_num)



SELECT flight_ID, SUM(bilet_price) AS bilet_price, COUNT(bilet_num)  
FROM s_bilet
	GROUP BY flight_ID
	
SELECT flight_ID, SUM(bilet_price) AS bilet_num 
FROM s_bilet
	GROUP BY flight_ID
	HAVING COUNT(flight_ID)<2
	



SELECT plane_type, plane_capacity, airline_name 
FROM s_plane a JOIN s_airline b ON a.airline_num=b.airline_num


SELECT  timetable_timeofdeparture, timetable_timeofarrival, flight_status
 FROM s_timetable f, s_flight c
 WHERE f.timetable_numofflight=c.timetable_numofflight 
 
 SELECT passenger_name, bilet_place, bilet_class
 FROM s_passenger f, s_bilet c, s_flight b
 WHERE f.passenger_num=c.passenger_num  AND  
  c.flight_ID=b.flight_ID 
  

SELECT 	b.passenger_name  AS "��� ���������", 
	b.passenger_priznak AS "�������" 
FROM  s_passenger b
WHERE b.passenger_path = '������' 


SELECT '����� � '+CONVERT(CHAR(6),bilet_num)+ 
'�� ����� ' AS "�����", 
SUM(bilet_price) AS "�����",  
COUNT(bilet_num) AS "����������" FROM s_bilet
		GROUP BY bilet_num
UNION
SELECT '�����: ', SUM(bilet_price), COUNT(bilet_num) FROM s_bilet ORDER BY 1





�������������
	
CREATE VIEW s_passenger
AS
SELECT s_bilet.bilet_place, s_bilet.bilet_class,
        s_passenger.passenger_name, s_flight.flight_ID
FROM s_passenger, s_bilet, s_flight  INNER JOIN
    s_passenger ON s_passenger.passenger_name=s_bilet.passenger_name  AND  
  s_flight.flight_ID=s_bilet.flight_ID 
WHERE flight_ID 	
BETWEEN 12 AND 17

GO

SELECT 	a.passenger_name AS "��� ���������", 
	b.bilet_place AS "����� �����", 
	b.bilet_class AS "�����",  
FROM s_passenger a, s_bilet b
WHERE a.passenger_num=b.passenger_num 
	
	
 


