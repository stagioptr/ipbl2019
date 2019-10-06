using STAGIOPTR.Database;
using STAGIOPTR.Droid.Database;
using System.IO;
using Xamarin.Forms;

[assembly: Dependency(typeof(DatabasePath))]
namespace STAGIOPTR.Droid.Database
{
    public class DatabasePath : IPath
    {
        public string GetPath(string DatabaseName)
        {
            string PersonalPath = System.Environment.GetFolderPath(System.Environment.SpecialFolder.Personal);
            string DatabasePath = Path.Combine(PersonalPath, DatabaseName);
            return DatabasePath;
        }
    }
}