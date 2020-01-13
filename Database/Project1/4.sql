with result_table as ( 
	select max("avg_grade") as avg_grade, "GRADE", "MAJOR_ID"
	from
	(
		select sum("CREDIT"*G."GRADE")/sum("CREDIT") as avg_grade, G."STUDENT_ID", S."MAJOR_ID", S."GRADE", "COLLEGE_NAME", "MAJOR_NAME"
		from "GRADE" as G natural join "COURSE" as C, "STUDENTS" as S, "COLLEGE" as CO
		where S."STUDENT_ID" = G."STUDENT_ID" and CO."MAJOR_ID" = S."MAJOR_ID" and C."YEAR" < 2019 and S."GRADE" < 5
 		group by G."STUDENT_ID", S."MAJOR_ID", S."GRADE", "COLLEGE_NAME", "MAJOR_NAME"
		order by "STUDENT_ID"
	) as F
	group by "GRADE", "MAJOR_ID"
	order by "MAJOR_ID", "GRADE"
	), add_table as (
		select sum("CREDIT"*G."GRADE")/sum("CREDIT") as avg_grade, G."STUDENT_ID", S."MAJOR_ID", S."GRADE", "COLLEGE_NAME", "MAJOR_NAME"
		from "GRADE" as G natural join "COURSE" as C, "STUDENTS" as S, "COLLEGE" as CO
		where S."STUDENT_ID" = G."STUDENT_ID" and CO."MAJOR_ID" = S."MAJOR_ID" and C."YEAR" < 2019 and S."GRADE" < 5
		group by G."STUDENT_ID", S."MAJOR_ID", S."GRADE", "COLLEGE_NAME", "MAJOR_NAME"
		order by "STUDENT_ID"
	)
select "avg_grade" as "GPA", "STUDENT_ID", "GRADE", "MAJOR_NAME", "COLLEGE_NAME"
from result_table natural join add_table
order by "MAJOR_NAME", "GRADE"