create database healthcare;
use healthcare;
CREATE TABLE Patients (
    PatientID INT PRIMARY KEY,
    Name VARCHAR(100),
    DateOfBirth DATE,
    MedicalHistory TEXT
);
CREATE TABLE Doctors (
    DoctorID INT PRIMARY KEY,
    Name VARCHAR(100),
    Specialization VARCHAR(100),
    Availability VARCHAR(100)
);
CREATE TABLE Appointments (
    AppointmentID INT PRIMARY KEY,
    PatientID INT,
    DoctorID INT,
    AppointmentDate DATETIME,
    Status VARCHAR(20),
    FOREIGN KEY (PatientID) REFERENCES Patients(PatientID),
    FOREIGN KEY (DoctorID) REFERENCES Doctors(DoctorID)
);
INSERT INTO Patients (PatientID, Name, DateOfBirth, MedicalHistory) 
VALUES (1, 'John Doe', '1990-05-15', 'No significant medical history');
INSERT INTO Doctors (DoctorID, Name, Specialization, Availability) 
VALUES (1, 'Dr. Smith', 'Cardiologist', 'Monday, Wednesday, Friday');
INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, Status) 
VALUES (1, 1, 1, '2024-05-10 09:00:00', 'Scheduled');
DELIMITER //
CREATE TRIGGER UpdateAvailability
AFTER UPDATE ON Appointments
FOR EACH ROW
BEGIN
    IF NEW.Status = 'Scheduled' OR OLD.Status = 'Scheduled' THEN
        UPDATE Doctors SET Availability = 'Booked' WHERE DoctorID = NEW.DoctorID;
    ELSE
        UPDATE Doctors SET Availability = 'Available' WHERE DoctorID = OLD.DoctorID;
    END IF;
    END ;
//
DELIMITER ;
CREATE VIEW DoctorSchedule AS
SELECT Doctors.Name AS DoctorName, Appointments.AppointmentDate, Appointments.Status
FROM Appointments
JOIN Doctors ON Appointments.DoctorID = Doctors.DoctorID
WHERE Appointments.AppointmentDate > NOW();
select * from Patients;
select * from Doctors;
SELECT * FROM DoctorSchedule;