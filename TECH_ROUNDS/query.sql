-- find city wise proportion of registered users from india

SELECT
    city,
    COUNT(*) AS proportion
FROM
    user_location
WHERE
    country = 'India'
GROUP BY
    city;

-- take all purchase in last 30 days and identify most recently purchased by gender

SELECT
    user_id, booking_time
FROM
    crm_event
WHERE
    booking_time > NOW() - INTERVAL 30 DAY;

-- inner join user and payment table


(SELECT
    payment.plan_name
from
    payment
INNER JOIN 
    user_profile
ON 
    user_profile.user_id = payment.user_id
WHERE
    payment.plan_start_date > NOW() - INTERVAL 30 DAY AND user_profile.gender = 'M'
ORDER BY
    payment.plan_start_date DESC
LIMIT
    1)

UNION ALL

(SELECT
    payment.plan_name
from
    payment 
INNER JOIN 
    user_profile
ON 
    user_profile.user_id = payment.user_id
WHERE
    payment.plan_start_date > NOW() - INTERVAL 30 DAY AND user_profile.gender = 'F'
ORDER BY
    payment.plan_start_date DESC
LIMIT
    1)





