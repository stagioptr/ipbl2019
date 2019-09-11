using System;
using System.Collections.Generic;
using System.Text;
using SQLite;
using System.Linq;
using StagioptrApp.Models;
using Xamarin.Forms;

namespace StagioptrApp.Database
{
    class DatabaseConnection
    {
        private SQLiteConnection _connection;

        public DatabaseConnection()
        {
            var dep = DependencyService.Get<IPath>();
            string path = dep.GetPath("database.sqlite");
            _connection = new SQLiteConnection(path);
            _connection.CreateTable<Pacientes>();
        }

        public void InsertPacientes (Pacientes paciente)
        {
            _connection.Insert(paciente);
        }

        public List<Pacientes> ListPacientes()
        {
            return _connection.Table<Pacientes>().ToList();
        }

        public Pacientes GetPacientesPerId(int id)
        {
            return _connection.Table<Pacientes>().Where(a => a.Id == id).FirstOrDefault();
        }

        public List<Pacientes> Search(string word)
        {
            return _connection.Table<Pacientes>().Where(a => a.Name.Contains(word)).ToList();
        }

        public void DeletePaciente (Pacientes paciente)
        {
            _connection.Delete(paciente);
        }

        public void UpdatePaciente(Pacientes paciente)
        {
            _connection.Update(paciente);
        }
    }
}
