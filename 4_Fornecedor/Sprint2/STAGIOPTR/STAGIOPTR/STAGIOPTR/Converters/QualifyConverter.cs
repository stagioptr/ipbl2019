using System;
using System.Globalization;
using Xamarin.Forms;

namespace STAGIOPTR.Converters
{
    public class QualifyConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string qualify = (string)value;
            switch (qualify)
            {
                case "Ótimo":
                    return "very_satisfied_white.png";
                case "Bom":
                    return "satisfied_white.png";
                case "Regular":
                    return "normal_white.png";
                case "Ruim":
                    return "dissatisfied_white.png";
                case "Péssimo":
                    return "very_dissatisfied_white.png";
                default:
                    return null;
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
