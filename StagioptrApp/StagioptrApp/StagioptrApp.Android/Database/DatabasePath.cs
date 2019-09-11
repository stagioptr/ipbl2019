using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Xamarin.Forms;
using StagioptrApp.Database;
using System.IO;
using StagioptrApp.Droid.Database;

[assembly:Dependency(typeof(DatabasePath))]
namespace StagioptrApp.Droid.Database
{
    public class DatabasePath : IPath
    {
        public string GetPath(string DatabaseName)
        {
            //caminho da pasta pessoal no dispositivo android para criação do banco
            string PersonalPath = System.Environment.GetFolderPath(System.Environment.SpecialFolder.Personal);
            string DatabasePath = Path.Combine(PersonalPath, DatabaseName);
            return DatabasePath;
        }
    }
}