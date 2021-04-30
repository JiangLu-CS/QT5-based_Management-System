-- ----------------------------
-- Table structure for teacher
-- ----------------------------
CREATE TABLE teacher(
  tid bigint identity(1000,1) primary key,
  tname varchar(20) NOT NULL,
  tpassword varchar(20) NOT NULL,
  tstatus bit
)
-- ----------------------------
-- Records of teacher
-- ----------------------------
INSERT INTO teacher VALUES ('董守玲','123456',0);
INSERT INTO teacher VALUES('袁华','123456',0);
INSERT INTO teacher VALUES('解晓萌','123456',0);
-- ----------------------------
-- Table structure for book
-- ----------------------------
CREATE TABLE book(
 bid int identity(1,1) primary key,
 bname varchar(20),
 price float
 )
 -- ----------------------------
-- Records of book
-- ----------------------------
INSERT INTO book VALUES('数据库概论',20);
INSERT INTO book VALUES('计算机网络',22);
INSERT INTO book VALUES('计算机体系结构',18);
-- ----------------------------
-- Table structure for major
-- ----------------------------
CREATE TABLE major(
 mid bigint identity(10000,1) primary key,
 mname varchar(20),
 headteacher bigint,
 foreign key(headteacher) references teacher(tid)
 )
-- ----------------------------
-- Records of major
-- ----------------------------
INSERT INTO major VALUES('网络工程',1000);
INSERT INTO major VALUES('计科',1001);
INSERT INTO major VALUES('信安',1002);
-- ----------------------------
-- Table structure for dorm
-- ----------------------------
CREATE TABLE dorm(
 did bigint identity(100,1) primary key,
 remark text,
 manager varchar(20)
)
-- ----------------------------
-- Records of dorm
-- ----------------------------
INSERT INTO dorm VALUES('十二点后不熄灯','王芳');
INSERT INTO dorm VALUES('无','李明');
INSERT INTO dorm VALUES('宿舍整洁','马霞');


-- ----------------------------
-- Table structure for student
-- ----------------------------
CREATE TABLE student (
  stuid bigint identity(20180001,1) primary key,
  sname varchar(10) NOT NULL,
  ssex varchar(4) NOT NULL,
  age int,
  smajor bigint,
  spassword varchar(10),
  dormnum bigint,
  foreign key(smajor) references major(mid),
  foreign key(dormnum) references dorm(did)
) 

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO student VALUES ('张三', '男', 19,10001, '123456', 100);
INSERT INTO student VALUES ('李四', '男', 18,10000, '123456',101);
INSERT INTO student VALUES ('小红', '女', 19,10002, '123456',102);
-- ----------------------------
-- Table structure for evaluation
-- ----------------------------
CREATE TABLE evaluation(
 stuid bigint,
 tid bigint,
 content text,
 foreign key(stuid) references student(stuid),
 foreign key(tid) references teacher(tid),
 primary key(stuid,tid)
 )
 -- ----------------------------
-- Records of evaluation
-- ----------------------------
INSERT INTO evaluation VALUES(20180001,1000,'老师教学认真细致，教学生动有趣，讲解知识点覆盖面广，课后热心回答同学问题');
INSERT INTO evaluation VALUES(20180001,1001,'老师认真负责，但是讲课不够生动有趣');
INSERT INTO evaluation VALUES(20180001,1002,'老师讲课细致，知识点覆盖面广，讲课内容实用性强，但是讲课速度过快');
-- ----------------------------
-- Table structure for course
-- ----------------------------
CREATE TABLE course (
  cid bigint identity(100,1) primary key,
  cname varchar(20),
  book int,
  teacher bigint,
  classhour float,
  credit float,
  foreign key(book) references book(bid),
  foreign key(teacher) references teacher(tid)
) 
 -- ----------------------------
-- Records of course
-- ----------------------------
INSERT INTO course VALUES ('数据库',1,1000,48, 3);
INSERT INTO course VALUES ('计网',2,1001,60, 5);
INSERT INTO course VALUES ('计组',3,1002,45, 3);
-- ----------------------------
-- Table structure for score
-- ----------------------------
CREATE TABLE score (
 cid bigint,
 stuid bigint,
 grade float
 foreign key(cid) references course(cid),
 foreign key(stuid) references student(stuid),
 primary key(stuid,cid)
)
-- ----------------------------
-- Records of score
-- ----------------------------
INSERT INTO score VALUES (100,20180001,88);
INSERT INTO score VALUES(101,20180001,90);
INSERT INTO score VALUES(102,20180001,86);

