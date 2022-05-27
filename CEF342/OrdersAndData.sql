CREATE DATABASE Orders;

USE Orders;

CREATE TABLE tblCustomers(
    CustomerID VARCHAR(5) NULL PRIMARY KEY,
    CompanyName VARCHAR(40) NOT NULL,
    ContactName VARCHAR(30) NULL,
    ContactTitle VARCHAR(30) NULL,
    Address VARCHAR(60) NULL,
    City VARCHAR(15) NULL,
    Region VARCHAR(15) NULL,
    PostalCode VARCHAR(10) NULL,
    Country VARCHAR(15) NULL DEFAULT "Canada",
    Phone VARCHAR(24) NULL,
    Fax VARCHAR(24) NULL
);

CREATE TABLE tblOrdersDetails (
    OrderID INT NULL,
    ProductID INT NULL,
    UnitPrice REAL NOT NULL,
    Quantity SMALLINT NOT NULL CHECK(Quantity > 0),
    Discount REAL NOT NULL,
    PRIMARY KEY(OrderID, ProductID),
    FOREIGN KEY (OrderID) REFERENCES tblOrders(OrderID) ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (ProductID) REFERENCES tblProducts(ProductID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE tblOrders (
    OrderID INT NULL PRIMARY KEY,
    CustomerID VARCHAR(5) NOT NULL,
    EmployeeID INT NULL,
    ShipName VARCHAR(40) NULL,
    ShipAddress VARCHAR(60) NULL,
    ShipCity VARCHAR(15) NULL,
    ShipRegion VARCHAR(15) NULL,
    ShipPostalCode VARCHAR(10) NULL,
    ShipCountry VARCHAR(15) NULL,
    ShipVia INT NULL,
    OrderDate DATE NULL,
    RequiredDate DATE NULL,
    ShippedDate DATE NULL CHECK (ShippedDate > OrderDate),
    Freight REAL NULL,
    FOREIGN KEY (CustomerID) REFERENCES tblCustomers(CustomerID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE tblProducts (
    ProductID INT NOT NULL PRIMARY KEY,
    SupplierID INT NULL,
    CategoryID INT NULL,
    ProductName VARCHAR(40) NOT NULL,
    EnglishName VARCHAR(40) NULL,
    QuantityPerUnit VARCHAR(40) NOT NULL,
    UnitPrice REAL NULL,
    UnitsInStock SMALLINT NULL,
    UnitsOnOrder SMALLINT NULL,
    ReorderLevel SMALLINT NULL,
    Discountinued BIT NOT NULL,
    FOREIGN KEY (SupplierID) REFERENCES tblSupplier(SupplierID) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE tblShippers (
    ShipperID INT NOT NULL PRIMARY KEY,
    CompanyName VARCHAR(40) NOT NULL UNIQUE
);

CREATE TABLE tblSupplier (
    SupplierID INT NOT NULL PRIMARY KEY,
    Name VARCHAR(50) NULL,
    Address VARCHAR(50) NULL,
    City VARCHAR(50) NULL,
    Province VARCHAR(50) NULL
);