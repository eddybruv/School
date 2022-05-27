-- Question 5 --

SELECT
    tblCustomers.CustomerID,
    tblCustomers.Address,
    tblCustomers.CompanyName,
    tblCustomers.ContactTitle,
    tblCustomers.Phone
FROM
    `tblCustomers`
    INNER JOIN tblOrders ON tblCustomers.CustomerID = tblOrders.CustomerID
WHERE
    tblOrders.OrderDate NOT BETWEEN '2011-01-01'
    AND '2001-12-31' -- Question 6 --
SELECT
    ProductID,
    ProductName,
    UnitPrice,
    UnitsInStock
FROM
    tblProducts
WHERE
    UnitsOnOrder = 0;

-- Question 7 --

SELECT
    tblCustomers.CustomerID,
    tblCustomers.ContactName,
    tblOrders.OrderID
FROM
    tblCustomers
    INNER JOIN tblOrders ON tblCustomers.CustomerID = tblOrders.CustomerID
WHERE
    tblCustomers.CustomerID IN (
        SELECT
            CustomerID
        FROM
            tblCustomers
        WHERE
            City = 'London'
    );

--Question 8--

SELECT
    tblProducts.ProductName,
    tblSupplier.Name As Supplier_Name
FROM
    tblSupplier
    INNER JOIN tblProducts ON tblSupplier.SupplierID = tblProducts.SupplierID
WHERE
    tblSupplier.Name = 'Supplier A'
    OR tblSupplier.Name = 'Supplier B';

/* Question 9 */
SELECT
    ProductName,
    QuantityPerUnit
FROM
    tblProducts
WHERE
    QuantityPerUnit LIKE '%boxes%'