with base_table as
(
	select G."STUDENT_ID", G."COURSE_ID", "CREDIT", "YEAR", "SEMESTER", S."GRADE" as GRADE_NUMBER, CO."MAJOR_NAME", CO."COLLEGE_NAME", G."GRADE", S."NAME"
	from "STUDENTS" as S, "COURSE" as C, "GRADE" as G, "COLLEGE" as CO
	where S."STUDENT_ID" = G."STUDENT_ID" and G."COURSE_ID" = C."COURSE_ID" and CO."MAJOR_ID" = S."MAJOR_ID" and S."GRADE" = 4
	order by S."STUDENT_ID"
), avg_credit_table as
(
	select base_table."STUDENT_ID", sum(base_table."CREDIT" * base_table."GRADE")/sum("CREDIT") as avg_grade
	from base_table
	group by base_table."STUDENT_ID"
	having SUM("CREDIT") >= 40
)
select overlay("NAME" placing repeat('*', length("NAME")-1) from 2 for length("NAME")) as name_star, "STUDENT_ID", "MAJOR_NAME", "COLLEGE_NAME"
from avg_credit_table natural join base_table
where "avg_grade" = 
(
	select max("avg_grade")
	from avg_credit_table
) or "avg_grade" = 
(
	select min("avg_grade")
	from avg_credit_table
)
group by "avg_grade", name_star, "STUDENT_ID", "MAJOR_NAME", "COLLEGE_NAME"
order by "avg_grade" desc

