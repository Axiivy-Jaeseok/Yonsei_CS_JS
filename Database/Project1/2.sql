select "COURSE_NAME"
from
(
	select "COURSE_ID_PREFIX", "COURSE_ID_NO", "STUDENT_ID", "COURSE_NAME", count(*) as counted
	from "COURSE", "COURSE_REGISTRATION"
	where "COURSE"."COURSE_ID" = "COURSE_REGISTRATION"."COURSE_ID"
	group by "COURSE_ID_PREFIX", "COURSE_ID_NO", "STUDENT_ID", "COURSE_NAME"
	having count(*) > 1
	order by "COURSE_NAME"
) as T
group by "COURSE_NAME"
order by sum(counted) desc, "COURSE_NAME"
LIMIT 3