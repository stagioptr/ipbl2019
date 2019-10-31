using STAGIOPTR.Database;
using STAGIOPTR.Models;
using System.Collections.ObjectModel;
using System.Threading.Tasks;
using Xamarin.Forms;

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
        public Command LogoutCommand { get; set; }
        public Command LoadFoodsCommand { get; }

        private bool _isLoading;

        public bool IsLoading
        {
            get { return _isLoading; }
            set { SetProperty(ref _isLoading, value); }
        }

        public FeedingAddFoodViewModel(Feeding Feeding)
        {
            this.Feeding = Feeding;
            Foods = new ObservableCollection<Food>();
            LogoutCommand = new Command(this.Logout);
            this.IsLoading = true;
            _ = this.LoadAsync();
            FoodSelected = new Food();
            SelectItemVerify = new Command(ExecuteSelectItemVerify);
            LoadFoodsCommand = new Command(LoadAsyncList);
        }

        private async void LoadAsyncList()
        {
            await LoadAsync();
        }

        public override async Task LoadAsync()
        {
            var foods = await database.ListFood();
            this.Foods.Clear();
            foreach (var food in foods)
            {
                this.Foods.Add(food);
            }
            this.IsLoading = false;
        }

        private async void ExecuteSelectItemVerify()
        {
            this.Feeding.IdFood = this.FoodSelected.Id;
            this.Feeding.Food = this.FoodSelected.Name;
            await PushAsync<FeedingAddQtdViewModel>(this.Feeding);
        }

    }
}
