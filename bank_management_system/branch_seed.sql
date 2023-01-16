INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Busselton");
INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Collie");
INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Dunsborough");
INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Geraldton");
INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Perth");
INSERT INTO branch(branch_id, branch_name) VALUES(NULL, "Dwellingup");

INSERT INTO customer(cust_id, cust_first_name, cust_last_name, cust_email, branch_id)
VALUES(NULL, "Michael", "Vibert", "mike@hotmail.com", 1),
(NULL, "Kathryn", "Webb", "katie@gmail.com", 3),
(NULL, "Leon", "Wazaski", "leonboy@outlook.com", 2),
(NULL, "Varity", "Williams", "vjw@google.com", 6),
(NULL, "Garry", "Faulkner", "gazzae@ga.com", 5);

INSERT INTO account(acc_id, acc_balance, acc_type, acc_interest_rate, cust_id, branch_id, trans_id)
VALUES(NULL, 700, "SAV", 5.2, 1, 1, NULL ),
(NULL, 200.78, "SAV", 5.2, 4, 3, NULL ),
(NULL, 7000, "SAV", 5.2, 5, 2, NULL ),
(NULL, 1000, "SAV", 6.7, 6, 6, NULL ),
(NULL, 50000, "SAV", 4.2, 7, 5, NULL );