using SQLite;
using STAGIOPTR.Models;
using System.Collections.Generic;
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
            //CREATE TABLES
            _connection.CreateTable<Patient>();
            _connection.CreateTable<Address>();
            _connection.CreateTable<Food>();
            _connection.CreateTable<Feeding>();
            _connection.CreateTable<Sleep>();
            _connection.CreateTable<Emotional>();
            _connection.CreateTable<User>();
            _connection.CreateTable<UserLogged>();
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

        public Patient GetPatientPerId(int Id)
        {
            return _connection.Table<Patient>().Where(a => a.Id == Id).FirstOrDefault();
        }

        public Patient GetPatientPerEmail(string Email)
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

        public Food GetFoodPerId(int Id)
        {
            return _connection.Table<Food>().Where(a => a.Id == Id).FirstOrDefault();
        }

        public Food GetFoodPerName(string Name)
        {
            return _connection.Table<Food>().Where(a => a.Name == Name).FirstOrDefault();
        }

        public bool VerifyFoodExist(string Name)
        {
            Food result = _connection.Table<Food>().Where(a => a.Name == Name).FirstOrDefault();
            if (result != null)
                return true;
            else
                return false;
        }

        // Feeding
        public void InsertFeeding(Feeding Feeding)
        {
            _connection.Insert(Feeding);
        }
        public async Task<List<Feeding>> ListFeeding(int id)
        {
            return _connection.Query<Feeding>("select *from Feeding where IdPatient=? order by FoodTime desc limit 6", id);
        }

        //SLEEP
        public void InsertSleep(Sleep Sleep)
        {
            _connection.Insert(Sleep);
        }

        public async Task<List<Sleep>> GetSleep(int id)
        {
            return _connection.Query<Sleep>("select *from Sleep where IdPatient=? order by SleepTime desc", id);
        }
        //EMOTIONAL

        public void InsertEmotional(Emotional Emotional)
        {
            _connection.Insert(Emotional);
        }

        public async Task<List<Emotional>> GetEmotional(int id)
        {
            return _connection.Query<Emotional>("select *from Emotional where IdPatient=? order by EmotionalTime desc",id);
        }

        // CRUD USER
        public void InsertUsers(User User)
        {
            _connection.Insert(User);
        }

        public User GetUserPerLogin(string Email, string Password)
        {
            return _connection.Table<User>().Where(a => a.Email == Email && a.Password == Password ).FirstOrDefault();
        }

        //CRUD LOGGED USER

        public void InsertLoggedUser(UserLogged userLogged)
        {
            _connection.Insert(userLogged);
        }


        public Patient GetLoggedUser()
        {
            if (_connection.Table<UserLogged>().FirstOrDefault() == null)
                return null;
            int Id = _connection.Table<UserLogged>().FirstOrDefault().IdUser;
            return _connection.Table<Patient>().Where(a => a.Id == Id).FirstOrDefault();
        }

        public void DeleteLoggedUser()
        {
            _connection.DeleteAll<UserLogged>();
        }
    }
}
