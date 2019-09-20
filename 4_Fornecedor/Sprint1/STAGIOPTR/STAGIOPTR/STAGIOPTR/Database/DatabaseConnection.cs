using SQLite;
using STAGIOPTR.Models;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Xamarin.Forms;

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
            _connection.CreateTable<Sleep>();
        }

        // CRUD PATIENTS
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

        public async Task<List<Patient>> ListPatients()
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

        public Patient getPatientPerEmail(string Email)
        {
            return _connection.Table<Patient>().Where(a => a.Email == Email).FirstOrDefault();
        }
        
        // CRUD FOODS
        public void InsertFood(Food Food)
        {
            _connection.Insert(Food);
        }

        public void UpdateFood(Food Food)
        {
            _connection.Update(Food);
        }

        public void DeleteFood(Food Food)
        {
            _connection.Delete(Food);
        }

        public async Task<List<Food>> ListFood()
        {
            return _connection.Table<Food>().ToList();
        }
        public List<Food> SearchFood(string word)
        {
            return _connection.Table<Food>().Where(a => a.Name.Contains(word)).ToList();
        }

        public Food getFoodPerId(int Id)
        {
            return _connection.Table<Food>().Where(a => a.Id == Id).FirstOrDefault();
        }

        // Feeding
        public void InsertFeeding(Feeding Feeding)
        {
            _connection.Insert(Feeding);
        }
        public async Task<List<Feeding>> ListFeeding()
        {
            return _connection.Table<Feeding>().Where(a=> a.IdPatient == Id).ToList();
        }
    }
}
