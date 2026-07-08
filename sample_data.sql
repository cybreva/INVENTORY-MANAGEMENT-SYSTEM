-- Inventory Management System
-- Sample Data
-- MySQL 8.4

USE inventory_db;

INSERT INTO categories (category_name)
VALUES
('Electronics'),
('Furniture'),
('Stationery');

INSERT INTO suppliers (supplier_name, phone, email, address)
VALUES
('ABC Electronics', '9876543210', 'abc@gmail.com', 'Delhi'),
('XYZ Traders', '9123456780', 'xyz@gmail.com', 'Mumbai');