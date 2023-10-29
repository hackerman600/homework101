sudo systemctl start mysql

sudo mysql -u root -p;

create user myuser identified by "mypassword123";
create database myexampledatabase;
grant all privileges on myexampledatabase.* to myuser;
flush privileges;
select user();


create table myexampletable(id int primary key auto_increment, name varchar(80) unique, gender int);
insert into myexampletable(name, gender) values("myname", 1);
insert into myexampletable(name, gender) values("myname2", 0);
insert into myexampletable(name, gender) values("myname3", 1);
insert into myexampletable(name, gender) values("myname4", 0);
insert into myexampletable(name, gender) values("myname5", 1);
insert into myexampletable(name, gender) values("myname6", 0);
insert into myexampletable(name, gender) values("myname7", 1);
insert into myexampletable(name, gender) values("myname8", 0);

insert into myexampletable(name, gender) values("myname9", 1);
insert into myexampletable(name, gender) values("myname10", 0);
insert into myexampletable(name, gender) values("myname11", 1);
insert into myexampletable(name, gender) values("myname12", 0);
insert into myexampletable(name, gender) values("myname13", 1);
insert into myexampletable(name, gender) values("myname14", 0);
insert into myexampletable(name, gender) values("myname15", 1);
insert into myexampletable(name, gender) values("myname16", 0);

alter table myexampletable modify id int; --drop the auto increment
alter table myexampletable drop primary key;

--shuffle the table; 
create table mynewexampletable as select name, gender from myexampletable order by rand();
alter table mynewexampletable add column id int;
alter table mynewexampletable modify column id int first;
set @incr = 0;
update mynewexampletable set id = (@incr := @incr + 1); 
alter table mynewexampletable add index(name)

--show views and tables in database that we have hypothetically already created.
select table_name from information_schema.tables where table_type = "base table" and schema_table = "myexampledatabase";
select table_name from information_schema.tables where table_type = "view" and schema_table = "myexampledatabase";

alter table mynewexampletable rename column id to Id;
alter table mynewexampletable rename column name to Name;
alter table mynewexampletable rename column gender to Gender;

alter table myexampletable rename to Myexampletable;
update Myexampletable set Name = concat(upper(left(Name,1)), lower(right(Name,length(Name)-1)))

--show columns and rows.
select t1.rows, t2.columns from (select count(*) as "rows" from Myexampletable) as t1 cross join (select count(column_name) as "columns"
from information_schema.columns where table_schema = "myexampledatabase" and table_
name = "Myexampletable") as t2;

create myexampletable2(id int primary key auto_increment, salary varchar(80));
create table myexampletable2(id int primary key auto_increment, salary varchar(80));
alter table myexampletable2 modify column salary int;
insert into myexampletable2(salary) values(304930);
insert into myexampletable2(salary) values(143431); 
insert into myexampletable2(salary) values(278321); 
insert into myexampletable2(salary) values(317627);
insert into myexampletable2(salary) values(122333);
insert into myexampletable2(salary) values(321211);
insert into myexampletable2(salary) values(767662);
insert into myexampletable2(salary) values(215656);
insert into myexampletable2(salary) values(213213);
insert into myexampletable2(salary) values(122212);
insert into myexampletable2(salary) values(324323);
insert into myexampletable2(salary) values(983287);
insert into myexampletable2(salary) values(234322);
insert into myexampletable2(salary) values(324322);
insert into myexampletable2(salary) values(122121);
insert into myexampletable2(salary) values(1122123);
insert into myexampletable2(salary) values(4324348);
insert into myexampletable2(salary) values(435843);
insert into myexampletable2(salary) values(234889);
insert into myexampletable2(salary) values(432545);
insert into myexampletable2(salary) values(234344);
insert into myexampletable2(salary) values(323323);
insert into myexampletable2(salary) values(968855);

select t.Id, t.Name, s.Salary from mynewexampletable as t join myexampletable2 as s on t.Id = s.id order by id asc;

