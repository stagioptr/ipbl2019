using System.Collections.ObjectModel;
using StagioptrApp.Database;
using StagioptrApp.Models;

namespace StagioptrApp.ViewModels
{
    public class PacienteAlterViewModel
    {
        public Pacientes pacientes { get; set; }
        DatabaseConnection database = new DatabaseConnection();

        public PacienteAlterViewModel()
        {
            
        }
    }
}
