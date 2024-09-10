-- Keep a log of any SQL queries you execute as you solve the mystery.

-- List the schema for the entire database
.schema

-- List the database tables
.tables

-- Find report that matches crime's date and location
SELECT description FROM crime_scene_reports 
WHERE street = 'Humphrey Street'
AND year = 2023
AND day = 28
AND month = 7;

-- Check interrogation transcripts for mention of bakery
SELECT transcript FROM interviews
WHERE year = 2023
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';
-- Conversation took less than 1 minute. Earliest flight taken out of Fiftyville. Ticket purchased by accomplice

-- Search security logs for cars that appears in the parking lot during time of crime
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute BETWEEN 15 AND 25;

-- See who made a withdrawl during the time of the crime
SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';
-- Bruce, Diana, Iman and Luca suspected

-- Find people associated with atm account number
SELECT people.name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street';
-- no leads - same suspects

-- Check phone calls within crime's time frame
SELECT caller FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration <= 60;

-- Check caller names
SELECT people.name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60;

-- Fiftville's flights
SELECT * FROM airports
WHERE city = 'Fiftyville';

-- Check earliest flight on day of crime
SELECT * FROM flights
WHERE origin_airport_id = 8
AND flights.year = 2023
AND flights.month = 7
AND flights.day = 29;

-- Find where flight arrives
SELECT airports.city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = 8
AND flights.year = 2023
AND flights.month = 7 AND flights.day = 29
AND flights.hour = 8 AND flights.minute = 20;
-- Arrives in NY

-- List passenger names on flight
SELECT people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.origin_airport_id = airports.id
WHERE airports.city = 'Fiftyville'
AND flights.year = 2023
AND flights.month = 7
AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20;
-- Bruce is the killer

-- Get Bruce's phone number
SELECT phone_number FROM people
WHERE name = 'Bruce';

-- Find Bruce's accomplice
SELECT people.name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2023
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
AND phone_calls.caller = '(367) 555-5533';
-- Bruce's accomplice is Robin
