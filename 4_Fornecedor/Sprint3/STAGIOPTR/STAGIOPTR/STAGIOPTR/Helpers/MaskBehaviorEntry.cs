using System;
using System.Globalization;
using System.Text.RegularExpressions;
using Xamarin.Forms;

namespace STAGIOPTR.Helpers
{
    public class MaskBehaviorEntry : Behavior<Entry>
    {
        public enum MaskTypeEnum
        {
            Default,
            Cpf,
            Cnpj,
            Cep,
            CelularTelefone,
            Data,
            DataValidadeCartaoCredito,
            Decimal,
            Email,
            TitleCase
        }

        public int MaxLength { get; set; }
        public bool Formatado { get; set; }
        internal const int LENGTH_CPF = 11;
        internal const int LENGTH_CNPJ = 14;
        internal const int LENGTH_DATE = 8;
        internal const int LENGTH_DATE_CREDIT_CARD = 6;
        internal const int LENGTH_PHONE_SEM_MASCARA_10 = 10;
        internal const int LENGTH_PHONE_SEM_MASCARA_11 = 11;
        internal const int LENGTH_PHONE_SEM_MASCARA_14 = 14;
        internal const int LENGTH_DECIMAL = 2;
        internal const int LENGTH_CEP = 8;

        const string EmailRegex = @"^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$";
        static readonly BindablePropertyKey IsValidPropertyKey = BindableProperty.CreateReadOnly("IsValid", typeof(bool), typeof(MaskBehaviorEntry), false);
        public static readonly BindableProperty IsValidProperty = IsValidPropertyKey.BindableProperty;
        public static BindableProperty MaskEntryProperty = BindableProperty.Create(nameof(MaskEntryProperty), typeof(MaskTypeEnum), typeof(MaskBehaviorEntry), MaskTypeEnum.Default, BindingMode.TwoWay);

        /// <summary>
        /// (Validação via code behind) Valida o e-mail se o MaskType estiver setado como "Email". Exemplo: if (behaviorEmail.IsValid) ...
        /// </summary>
        public bool IsValid
        {
            get { return (bool)base.GetValue(IsValidProperty); }
            private set { base.SetValue(IsValidPropertyKey, value); }
        }

        public MaskTypeEnum MaskType
        {
            get { return (MaskTypeEnum)GetValue(MaskEntryProperty); }
            set
            {
                SetValue(MaskEntryProperty, value);
            }
        }

        protected override void OnAttachedTo(Entry bindable)
        {
            base.OnAttachedTo(bindable);
            bindable.TextChanged += OnEntryTextChanged;
        }

        protected override void OnDetachingFrom(Entry bindable)
        {
            base.OnDetachingFrom(bindable);
            bindable.TextChanged -= OnEntryTextChanged;
        }

        void OnEntryTextChanged(object sender, TextChangedEventArgs e)
        {
            var entry = (Entry)sender;
            var entryText = e.NewTextValue;
            var numberFormat = (NumberFormatInfo)CultureInfo.InvariantCulture.NumberFormat.Clone();
            numberFormat.NumberDecimalSeparator = ",";

            if (entryText != null)
            {
                var entryLength = entryText.Length;
                var entryVal = 0m;

                switch (MaskType)
                {
                    case MaskTypeEnum.Cpf:

                        if (entryLength == LENGTH_CPF && !Formatado)
                        {
                            entryVal = Convert.ToUInt64(entryText);
                            entryText = entryVal.ToString(@"000\.000\.000\-00");
                            Formatado = true;
                        }
                        else if (entryText.RemoveNonNumbers().Length > LENGTH_CPF)
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_CPF && Formatado)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_CPF ? Color.Red : Color.Black;

                        break;

                    case MaskTypeEnum.Cnpj:

                        if (entryLength == LENGTH_CNPJ && !Formatado)
                        {
                            entryVal = Convert.ToUInt64(entryText);
                            entryText = entryVal.ToString(@"00\.000\.000\/0000\-00");
                            Formatado = true;
                        }
                        else if (entryText.RemoveNonNumbers().Length > LENGTH_CNPJ)
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_CNPJ && Formatado)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_CNPJ ? Color.Red : Color.Black;

                        break;

                    case MaskTypeEnum.CelularTelefone:

                        if ((entryLength == LENGTH_PHONE_SEM_MASCARA_10 || entryLength == LENGTH_PHONE_SEM_MASCARA_11 || entryLength == LENGTH_PHONE_SEM_MASCARA_14))
                        {
                            entryText = entryText.RemoveNonNumbers();
                            entryVal = Convert.ToUInt64(entryText);
                            entryText = string.Format("{0:(##) ####-####}", entryVal);
                            Formatado = true;
                        }
                        else if (entryLength == 15)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            entryVal = Convert.ToUInt64(entryText);
                            entryText = string.Format("{0:(##) #####-####}", entryVal);
                            Formatado = true;
                        }
                        else if ((entryLength > LENGTH_PHONE_SEM_MASCARA_10) && (entryLength > LENGTH_PHONE_SEM_MASCARA_11) && (entryLength > LENGTH_PHONE_SEM_MASCARA_14))
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_PHONE_SEM_MASCARA_14 && Formatado)
                        {
                            entryText = entry.Text.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_PHONE_SEM_MASCARA_11 ? Color.Red : Color.Black;

                        break;

                    case MaskTypeEnum.Data:

                        if (entryLength == LENGTH_DATE && !Formatado)
                        {
                            entryText = Convert.ToUInt64(entryText).ToString(@"00/00/0000");
                            Formatado = true;
                        }
                        else if (entryText.RemoveNonNumbers().Length > LENGTH_DATE)
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_DATE && Formatado)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_DATE ? Color.Red : Color.Black;

                        break;

                    case MaskTypeEnum.DataValidadeCartaoCredito:

                        if (entryLength == LENGTH_DATE_CREDIT_CARD && !Formatado)
                        {
                            entryText = Convert.ToUInt64(entryText).ToString(@"00/0000");
                            Formatado = true;
                        }
                        else if (entryText.RemoveNonNumbers().Length > LENGTH_DATE_CREDIT_CARD)
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_DATE_CREDIT_CARD && Formatado)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_DATE_CREDIT_CARD ? Color.Red : Color.Black;

                        break;

                    case MaskTypeEnum.Decimal:

                        if (entryText != e.OldTextValue)
                        {
                            string strNumber = entryText.RemoveNonNumbers();

                            if (strNumber.Length > LENGTH_DECIMAL)
                            {
                                var pos = strNumber.Length - LENGTH_DECIMAL;
                                entryText = strNumber.Insert(pos, ",");
                                entry.Text = string.Format("{0:N2}", Convert.ToDecimal(entryText, numberFormat));
                            }
                        }

                        break;

                    case MaskTypeEnum.TitleCase:

                        if (MaxLength > 0)
                        {
                            if (entryLength > MaxLength)
                            {
                                entryText = entryText.Remove(entryLength - 1);
                                entry.Text = entryText;
                            }
                        }

                        entry.Text = Regex.Replace(entryText.ToLower(), @"(?<=\b(?:mc|mac)?)[a-zA-Z]", m => m.Value.ToUpper());

                        break;

                    case MaskTypeEnum.Email:

                        IsValid = Regex.IsMatch(entryText.ToLower(), EmailRegex, RegexOptions.IgnoreCase);
                        entry.TextColor = IsValid ? Color.Black : Color.Red;

                        break;

                    case MaskTypeEnum.Cep:

                        if (entryLength == LENGTH_CEP && !Formatado)
                        {
                            entryText = Convert.ToUInt64(entryText).ToString(@"00000-000");
                            Formatado = true;
                        }
                        else if (entryText.RemoveNonNumbers().Length > LENGTH_CEP)
                        {
                            entryText = entryText.Remove(entryLength - 1);
                        }
                        else if (entryLength < LENGTH_CEP && Formatado)
                        {
                            entryText = entryText.RemoveNonNumbers();
                            Formatado = false;
                        }

                        entry.Text = entryText;
                        entry.TextColor = entry.Text.Length < LENGTH_CEP ? Color.Red : Color.Black;

                        break;

                    default:

                        if (MaxLength > 0)
                        {
                            if (entryLength > MaxLength)
                            {
                                entryText = entryText.Remove(entryLength - 1);
                                entry.Text = entryText;
                            }
                        }

                        entry.TextColor = Color.Black;

                        break;
                }
            }
        }
    }
}
