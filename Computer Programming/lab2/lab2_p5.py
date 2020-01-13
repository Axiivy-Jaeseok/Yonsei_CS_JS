# Age in seconds Program
# This program will calculate a person's approximate age in seconds

# Get Person1's month, day, year of birth
p1_month_birth = int(input('Person 1: Enter month born (1-12): '))
p1_day_birth = int(input('Person 1: Enter day born (1-31): '))
p1_year_birth = int(input('Person 1: Enter year born (4-digit): '))

# Get Person2's month, day, year of birth
p2_month_birth = int(input('Person 2: Enter month born (1-12): '))
p2_day_birth = int(input('Person 2: Enter day born (1-31): '))
p2_year_birth = int(input('Person 2: Enter year born (4-digit): '))


# Determine number of seconds in a day, average month, and average year
numsecs_day = 24*60*60
numsecs_year = 365*numsecs_day

avg_numsecs_year = ((4*numsecs_year)+numsecs_day)//4
avg_numsecs_month = avg_numsecs_year//12

# Callculate approximate age in seconds
age_in_secs = (abs(p1_year_birth-p2_year_birth)*avg_numsecs_year)+\
                   (abs(p1_month_birth-p2_month_birth)*avg_numsecs_month)+\
                   (abs(p1_day_birth-p2_day_birth)*numsecs_day)

# output results
print('Age difference in seconds:', age_in_secs)

