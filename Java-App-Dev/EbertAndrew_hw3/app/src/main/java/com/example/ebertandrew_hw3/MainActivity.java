package com.example.ebertandrew_hw3;

import androidx.appcompat.app.AppCompatActivity;


import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;
import android.widget.Toast;

import com.example.ebertandrew_hw3.databinding.ActivityMainBinding;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //setContentView(R.layout.activity_main);

        //For using view binding
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        View view = binding.getRoot();
        setContentView(view);

    }
        public void calculateClicked (View view){ calculate();}

        public void calculate () {
            double total, tax, tip, grand_total;

            try {
                total = Double.parseDouble(binding.totalAmountValue.getText().toString());
                if (total < 0){
                    Toast.makeText(this, "Total can't be negative", Toast.LENGTH_SHORT).show();
                    return;
                }
            }
            catch (NumberFormatException e) {
                Toast.makeText(this, "Total can't be blank", Toast.LENGTH_SHORT).show();
                return;
            }

            try {
                tax = Double.parseDouble(binding.taxAmountValue.getText().toString());
                if (tax < 0){
                    Toast.makeText(this, "Tax can't be negative", Toast.LENGTH_SHORT).show();
                    return;
                }
            } catch (NumberFormatException e) {
                Toast.makeText(this, "Tax can't be blank", Toast.LENGTH_SHORT).show();
                return;
            }

            if (binding.radioButtonZero.isChecked()) {
                tip = 0;
                grand_total = total;
            }
            else if (binding.radioButtonFive.isChecked()) {
                tip = (total-tax) * 0.05;
                grand_total = total + tip;
            }
            else if (binding.radioButtonTen.isChecked()) {
                tip = (total-tax) * 0.1;
                grand_total = total + tip;
            }
            else if (binding.radioButtonTwenty.isChecked()) {
                tip = (total-tax) * 0.2;
                grand_total = total + tip;
            }
            else{
return;
            }


            DecimalFormat precision = new DecimalFormat("#,###.00");
            binding.tipAmountValue.setText("$ " + precision.format(tip));

            binding.grandTotalValue.setText("$ " + precision.format(grand_total));

        }


        public void clearClicked (View view){ clearForm();}


        public void clearForm () {
            binding.totalAmountValue.setText("");
            binding.taxAmountValue.setText("");
            binding.tipAmountValue.setText("$ 0.00");
            binding.grandTotalValue.setText("$ 0.00");
            binding.radioButtonZero.setChecked(true);
        }


}