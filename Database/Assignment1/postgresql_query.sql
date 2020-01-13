insert into database2019.assignment1 (num, name, address, phone, studentid) values (1, '김도영', '서울시 서대문구', '010-1111-1111', '2019111111');
insert into database2019.assignment1 (num, name, address, phone, studentid) values (2, '이지은', '서울시 마포구', '010-2222-2222', '2019222222');
insert into database2019.assignment1 (num, name, address, phone, studentid) values (3, '유재석', '서울시 서대문구', '010-3333-3333', '2018147505');

select * from database2019.assignment1;

update database2019.assignment1 set num=2019 where studentID = '2018147505';

select * from database2019.assignment1;

delete from database2019.assignment1 where phone='010-2222-2222';

select * from database2019.assignment1;