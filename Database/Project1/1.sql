select COU."YEAR", COL."MAJOR_NAME", count(distinct COU."COURSE_ID")
from "COLLEGE" COL, "COURSE" COU
where COL."MAJOR_ID" = COU."COURSE_ID_PREFIX" and COU."COURSE_ID_PREFIX" != 'XYZ'
group by COU."YEAR", COL."MAJOR_NAME"
order by COU."YEAR", count(distinct COU."COURSE_ID") DESC, COL."MAJOR_NAME";
