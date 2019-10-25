using STAGIOPTR.Database;
using STAGIOPTR.Models;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class FoodAddViewModel:BaseViewModel
    {
        private Food _food;
        DatabaseConnection database = new DatabaseConnection();
        public Command AddFoodCommand { get; }
        public Command LogoutCommand { get; set; }
        public Food Food
        {
            get { return _food; }
            set { SetProperty(ref _food, value); }
        }

        private string _errors;

        public string Errors
        {
            get { return _errors; }
            set { SetProperty(ref _errors, value); }
        }


        public FoodAddViewModel()
        {
            Food = new Food();
            LogoutCommand = new Command(this.Logout);
            AddFoodCommand = new Command(ExecuteAddFoodCommand);
        }

        private void ExecuteAddFoodCommand()
        {
            if (this.ValidationRules())
            {
                this.database.InsertFood(this.Food);
                Application.Current.MainPage.Navigation.PopAsync();
            }
        }

        private bool ValidationRules()
        {
            bool validation = true;

            if (string.IsNullOrWhiteSpace(this.Food.Name))
            {
                this.Errors = "Campo Nome obrigatório";
                validation = false;
            }

            if(database.VerifyFoodExist(this.Food.Name))
            {
                this.Errors = "Alimento já cadastrado";
                validation = false;
            }

            return validation;
        }

    }
}
