# test

# Test Plan and Corresponding Output

## High Level Test Plan

| Test Id | Description                         | Exp. i/p         | Exp. O/p                  | Actual O/p                | Test Type                         |
| ------- | ----------------------------------- | ---------------- | ------------------------- | ------------------------- | --------------------------------- | ----------- |
| H01     | Check if menu is displayed properly | Option Selection | Formatted Menu Page       | Formated Menu Page        | Requirements                      |
| H02     | Function working properly or not    | Function call    | Proper function Execution | Proper function Execution | Requirement                       |
| H03     | Switch case working                 | Option           | Function call             |                           | Function call according to option | Requirement |

# Low Level Test Plan

| Test Id | Description            | Exp. i/p               | Exp. O/p                               | Actual O/p                         | Test Type |
| ------- | ---------------------- | ---------------------- | -------------------------------------- | ---------------------------------- | --------- |
| L01     | Adding Contect to file | Detail of Contect      | Success->Menu;Failure->Exit            | Success->Menu;Failure->Exit        | Technical |
| L02     | Deleting Contect       | Number of Person       | Present->Deleted;Absent->Not found     | Present->Deleted;Absent->Not found | Technical |
| Lo3     | Editing Contect        | Number of Person       | Present->Edited;Absent->Not found      | Present->edited;Absent->Not found  | Technical |
| L04     | Display List           | Give option for search | Success->List of Contect;Failure->Menu | Success->List;Failure->error       | Technical |
