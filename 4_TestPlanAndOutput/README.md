# test

# Test Plan and Corresponding Output

## High Level Test Plan

| Test Id | Description                         | Exp. i/p         | Exp. O/p                  | Actual O/p                | Test Type                         |
| ------- | ----------------------------------- | ---------------- | ------------------------- | ------------------------- | --------------------------------- |
| H01     | Check if menu is displayed properly | Option Selection | Formatted Menu Page       | Formated Menu Page        | Requirements                      |
| H02     | Function working properly or not    | Function call    | Proper function Execution | Proper function Execution | Requirement                       |
| H03     | Switch case working                 | Option           | Function call             | Function call according to option | Requirement |

# Low Level Test Plan

| Test Id | Description            | Exp. i/p               | Exp. O/p                               | Actual O/p                         | Test Type |
| ------- | ---------------------- | ---------------------- | -------------------------------------- | ---------------------------------- | --------- |
| L01     | Adding Contact to file | Detail of Contact      | Success->Menu;Failure->Exit            | Success->Menu;Failure->Exit        | Technical |
| L02     | Deleting Contact       | Number of Person       | Present->Deleted;Absent->Not found     | Present->Deleted;Absent->Not found | Technical |
| Lo3     | Editing Contact        | Number of Person       | Present->Edited;Absent->Not found      | Present->edited;Absent->Not found  | Technical |
| L04     | Display List           | Give option for search | Success->List of Contact;Failure->Menu | Success->List;Failure->error       | Technical |
|L05      |Adding contacts         | 1 (option required)    |Success->space for entering details;Failure->Invalid|Success->space for entering details;Failure->Invalid|Technical|
