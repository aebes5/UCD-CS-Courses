package edu.ucdenver.salimlakhani.phonebook;

import android.app.AlertDialog;
import android.app.Dialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;

import java.util.ArrayList;

import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.DialogFragment;

import edu.ucdenver.salimlakhani.phonebook.databinding.DialogViewContactBinding;

public class ViewContactDialog extends DialogFragment {

    private ArrayList<Contact> contactList;
    private int position;
    private DialogViewContactBinding binding;


    public void setContactList(ArrayList<Contact> contactList) {
        this.contactList = contactList;
    }

    public void setPosition(int position) {
        this.position = position;
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {
        binding = DialogViewContactBinding.inflate(LayoutInflater.from(getContext()));

        AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
        builder.setView(binding.getRoot());


        Contact contact = contactList.get(position);


        binding.textViewName.setText(contact.getName());
        binding.textViewPhone.setText(contact.getPhone());
        binding.textViewEmail.setText(contact.getEmail());
        binding.textViewStreet.setText(contact.getAddress());
        binding.textViewCity.setText(contact.getCity());
        binding.textViewState.setText(contact.getState());
        binding.textViewZip.setText(contact.getZip());
        binding.textViewType.setText(contact.getContacttype());



        binding.buttonMainMenu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dismiss();
            }
        });

        binding.buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (position >= 0 && position < contactList.size()) {
                    contactList.remove(position);
                    MainActivity mainActivity = (MainActivity) getActivity();
                    mainActivity.deleteContact(contact);
                    dismiss();
                }
            }
        });



        return builder.create();
    }
}
