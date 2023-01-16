DROP TABLE IF EXISTS account;
DROP TABLE IF EXISTS trans;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS branch;

CREATE TABLE[branch](
	[branch_id] INTEGER NOT NULL PRIMARY KEY,
	[branch_name] TEXT NOT NULL
	);

CREATE TABLE [customer](
	[cust_id] INTEGER PRIMARY KEY,
	[cust_first_name] TEXT NOT NULL,
	[cust_last_name] TEXT NOT NULL,
	[cust_email] TEXT NOT NULL,
	[branch_id] INTEGER,
	FOREIGN KEY (branch_id) REFERENCES branch(branch_id)
);

CREATE TABLE [trans](
	[trans_id] INTEGER PRIMARY KEY,
	[trans_data_time] TEXT NOT NULL,
	[trans_valid] INTEGER NOT NULL,
	[trans_type] TEXT NOT NULL,
	[cust_id_w] INTEGER NOT NULL,
	[cust_id_d] INTEGER NOT NULL,

	FOREIGN KEY(cust_id_w) REFERENCES customer(cust_id),
	FOREIGN KEY(cust_id_d) REFERENCES customer(cust_id)
	);

CREATE TABLE[account](
	[acc_id] INTEGER PRIMARY KEY,
	[acc_balance] INTEGER NOT NULL,
	[acc_type] TEXT NOT NULL,
	[acc_interest_rate] INTEGER NOT NULL,
	[cust_id] INTEGER NOT NULL,
	[branch_id] INTEGER NOT NULL,

	FOREIGN KEY(cust_id) REFERENCES customer(cust_id),
	FOREIGN KEY(branch_id) REFERENCES branch(branch_id)
	);



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

INSERT INTO account(acc_id, acc_balance, acc_type, acc_interest_rate, cust_id, branch_id)
VALUES(NULL, 700, "SAV", 5.2, 1, 1 ),
(NULL, 200.78, "SAV", 5.2, 4, 3),
(NULL, 7000, "SAV", 5.2, 3, 2),
(NULL, 1000, "SAV", 6.7, 5, 6);

INSERT INTO trans(trans_id, trans_data_time, trans_valid, trans_type, cust_id_w, cust_id_d)
