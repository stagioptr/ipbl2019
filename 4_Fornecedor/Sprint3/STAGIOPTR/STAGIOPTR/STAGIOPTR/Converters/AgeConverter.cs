using System;
using System.Collections.Generic;
using System.Globalization;
using System.Text;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class AgeConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            DateTime Birthdate = (DateTime) value;
            int age = (int) DateTime.Now.Year - Birthdate.Year;
            if (DateTime.Now.DayOfYear < Birthdate.DayOfYear)
            {
                age = age - 1;
            }
            return age;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
