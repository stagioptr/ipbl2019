using StagioptrApp.Models;
using System.Collections.ObjectModel;
using StagioptrApp.Database;

namespace StagioptrApp.ViewModels
{
    public class PacientesViewModel
    {
        public ObservableCollection<Pacientes> Pacientes { get; set; }
        DatabaseConnection database = new DatabaseConnection();

        public PacientesViewModel()
        {
            this.Pacientes = new ObservableCollection<Pacientes>();
            this.Load();
        }

        public void Load()
        {
            this.database.ListPacientes().ForEach(delegate(Pacientes paciente){
                this.Pacientes.Add(paciente);
            });
        }

        public void Add(Pacientes paciente)
        {
            this.database.InsertPacientes(paciente);
        }

        public void Update(Pacientes paciente)
        {
            this.database.UpdatePaciente(paciente);
        }

        public void Delete(Pacientes paciente)
        {
            this.database.DeletePaciente(paciente);
            this.Pacientes.Remove(paciente);
        }
    }
}
