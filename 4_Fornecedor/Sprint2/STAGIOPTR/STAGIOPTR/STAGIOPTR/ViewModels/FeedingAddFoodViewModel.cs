using STAGIOPTR.Models;
using STAGIOPTR.Database;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;
using System.Diagnostics;

namespace STAGIOPTR.ViewModels
{
    public class FeedingAddFoodViewModel : BaseViewModel
    {
        DatabaseConnection database = new DatabaseConnection();
        private ObservableCollection<Food> _foods;
        public ObservableCollection<Food> Foods
        {
            get { return _foods; }
            set { SetProperty(ref _foods, value); }
        }
        private Feeding feeding;
        public Feeding Feeding
        {
            get { return feeding; }
            set { feeding = value; }
        }

        private Food _foodSelected;

        public Food FoodSelected
        {
            get { return _foodSelected; }
            set { SetProperty(ref _foodSelected, value); }
        }

        public Command SelectItemVerify { get; }


        public FeedingAddFoodViewModel(Feeding Feeding)
        {
            this.Feeding = Feeding;
            Foods = new ObservableCollection<Food>();
            FoodSelected = new Food();
            SelectItemVerify = new Command(ExecuteSelectItemVerify);
            this.LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var foods = await database.ListFood();
            this.Foods.Clear();
            foreach (var food in foods)
            {
                this.Foods.Add(food);
            }
        }

        private async void ExecuteSelectItemVerify()
        {
            this.Feeding.IdFood = this.FoodSelected.Id;
            this.Feeding.Food = this.FoodSelected.Name;
            await PushAsync<FeedingAddQtdViewModel>(this.Feeding);
        }

    }
}
