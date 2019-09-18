using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace STAGIOPTR.ViewModels
{
    public class BaseViewModel : INotifyPropertyChanged
    {
        //instanciamento da classe PropertyChanged para análisar alterações nas propriedades
        public event PropertyChangedEventHandler PropertyChanged;


        //callerMemberName = usado para invocar o nome da variavel que chamou(caller) o método ao inves de passar uma string
        //virtual = metodo pode ser alterado na sobrescrita
        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            //elvis operator... verifica se o parametro propertyName é nulo para, caso contrário
            //ele chamar o método invoke informando que o parâmetro teve mudanças
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }


        // método Genérico = T
        protected bool SetProperty<T>(ref T storage, T value, [CallerMemberName] string propertyName = null)
        {
            //verifica se a atualização da variavel tem o mesmo valor... se tiver o mesmo valor
            //a atualização não é realizada
            if (EqualityComparer<T>.Default.Equals(storage, value))
            {
                return false;
            }

            storage = value;
            OnPropertyChanged(propertyName);
            return true;
        }


        //Navegação entre ViewsModels
        public async Task PushAsync<TViewModel>(params object[] args) where TViewModel : BaseViewModel
        {
            var viewModelType = typeof(TViewModel);
            var viewModelTypeName = viewModelType.Name;
            var viewModelWordLength = "ViewModel".Length;
            var viewTypeName = $"STAGIOPTR.{viewModelTypeName.Substring(0, viewModelTypeName.Length - viewModelWordLength)}View";
            var viewType = Type.GetType(viewTypeName);

            var page = Activator.CreateInstance(viewType) as Page;

            var viewModel = Activator.CreateInstance(viewModelType, args);
            if (page != null)
            {
                page.BindingContext = viewModel;
            }

            await Application.Current.MainPage.Navigation.PushAsync(page);
        }

        //Navegação entre ViewsModels (Modal)
        public async Task PushModalAsync<TViewModel>(params object[] args) where TViewModel : BaseViewModel
        {
            var viewModelType = typeof(TViewModel);
            var viewModelTypeName = viewModelType.Name;
            var viewModelWordLength = "ViewModel".Length;
            var viewTypeName = $"STAGIOPTR.{viewModelTypeName.Substring(0, viewModelTypeName.Length - viewModelWordLength)}View";
            var viewType = Type.GetType(viewTypeName);

            var page = Activator.CreateInstance(viewType) as Page;

            var viewModel = Activator.CreateInstance(viewModelType, args);
            if (page != null)
            {
                page.BindingContext = viewModel;
            }

            await Application.Current.MainPage.Navigation.PushModalAsync(page);
        }

    }
}
