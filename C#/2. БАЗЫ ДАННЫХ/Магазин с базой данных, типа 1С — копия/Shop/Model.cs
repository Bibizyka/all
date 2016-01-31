namespace Shop
{
    using System;
    using System.Data.Entity;
    using System.Collections.Generic;

    public partial class Model : DbContext
    {
        public Model()
            : base("name=DbModel")
        {
        }


        // �������� DbSet ��� ������� ���� ��������, ������� ��������� �������� � ������. �������������� �������� 
        // � ��������� � ������������� ������ Code First ��. � ������ http://go.microsoft.com/fwlink/?LinkId=390109.

        // ������, ����� ������ ���������� � ���� ������
        public virtual DbSet<Product> Products { get; set; }
        public virtual DbSet<Purchase> Purchases { get; set; }
        public virtual DbSet<User> Users { get; set; }

        public static Model Create()
        {
            return new Model();
        }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            // �������, ��� ���� ����� ���� �� ������(� ������������ ����� ���� ����� �������)
            modelBuilder.Entity<User>().HasMany(c => c.Purchases);
        }
    }

    // ����� �������� - ����������� � ����������� ��������������� - ���, ���� ��� ������
    public class Product
    {
        // ���������� �������������
        public int Id { get; set; }

        // ��������
        public string Name { get; set; }

        // ��������
        public string Description { get; set; }

        // ����
        public decimal Price { get; set; }

        // ���� �����������-��������
        public DateTime CreateDate { get; set; }

        // ���������� ������������ ������
        public int Count { get; set; }

        // ���������� ���������� ������ � �����
        public int AllPurchasedCount { get; set; }
    }

    // ����� �������-���
    public class Purchase
    {
        // ���������� �������������
        public int Id { get; set; }

        // ��������� �������/�����
        public Product Product { get; set; }

        // ID ���������� ��������
        public int? ProductId { get; set; }

        // ����������
        public User User { get; set; }

        // ID ����������
        public int? UserId { get; set; }

        // ���� ������
        public DateTime CreateDate { get; set; }

        // ��������� = ���� * ����������
        public decimal Cost { get; set; }

        // ���������� ���������� ������
        public int PurchasedCount { get; set; }

        // ���������� ����(�������� �������������� � �����������, ����� ��������� �� ������)
        public bool Closed { get; set; }
    }

    // �������, ������� ��������� �������
    public class User
    {
        // ���������� �������������
        public int Id { get; set; }

        // ���
        public string UserName { get; set; }

        // ������
        public string Password { get; set; }

        // ���������� � ������������(�����, �������� � ��)
        public string UserInformation { get; set; }

        // ���� ������������ �� ��� ���������, ��� �� �����
        public ICollection<Purchase> Purchases { get; set; }

        // ������������� �� ���
        public bool IsAdmin { get; set; }
    }
}