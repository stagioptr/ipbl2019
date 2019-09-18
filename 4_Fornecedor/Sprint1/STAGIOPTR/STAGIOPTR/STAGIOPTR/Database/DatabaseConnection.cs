    using Xamarin.Forms;
using STAGIOPTR.Models;
using SQLite;
using System.Collections.Generic;

namespace STAGIOPTR.Database
{
    public class DatabaseConnection
    {
        private SQLiteConnection _connection;

        public DatabaseConnection()
        {
            var dep = DependencyService.Get<IPath>();
            string path = dep.GetPath("database.sqlite");
            _connection = new SQLiteConnection(path);
            _connection.CreateTable<Patient>();
            _connection.CreateTable<Address>();
            _connection.CreateTable<Food>();
            _connection.CreateTable<Feeding>();
        }

        public void InsertPatients(Patient Patient)
        {
            _connection.Insert(Patient);
        }

        public void UpdatePatient(Patient Patient)
        {
            _connection.Update(Patient);
        }

        public void DeletePatient(Patient Patient)
        {
            _connection.Delete(Patient);
        }

        public List<Patient> ListPatients()
        {
            return _connection.Table<Patient>().ToList();
        }
        public List<Patient> SearchPatients(string word)
        {
            return _connection.Table<Patient>().Where(a => a.Name.Contains(word)).ToList();
        }

        public Patient getPatientPerId(int Id)
        {
            return _connection.Table<Patient>().Where(a => a.Id == Id).FirstOrDefault();
        }
    }
}
