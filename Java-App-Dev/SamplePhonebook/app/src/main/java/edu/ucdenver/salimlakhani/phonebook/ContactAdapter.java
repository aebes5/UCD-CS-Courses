package edu.ucdenver.salimlakhani.phonebook;

import android.view.LayoutInflater;
import android.view.TextureView;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.widget.Toast;
import android.content.Intent;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class ContactAdapter extends RecyclerView.Adapter<ContactAdapter.ListItemHolder> {

    private MainActivity mainActivity;
    private ArrayList<Contact> list;
    private OnContactClickListener mListener;

    public ContactAdapter(MainActivity mainActivity, ArrayList<Contact> list) {
        this.mainActivity = mainActivity;
        this.list = list;
    }

    public interface OnContactClickListener {
        void onContactClick(int position);
    }

    public void setOnContactClickListener(OnContactClickListener listener) {
        mListener = listener;
    }

    @NonNull
    @Override
    public ListItemHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View listItem = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.list_layout, parent, false);

        return new ListItemHolder(listItem);
    }

    @Override
    public void onBindViewHolder(@NonNull ListItemHolder holder, int position) {
        Contact contact = list.get(position);

        holder.textViewName.setText(contact.getName());
        holder.textViewPhone.setText(contact.getPhone());
    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public class ListItemHolder extends RecyclerView.ViewHolder implements View.OnClickListener {
        private TextView textViewName;
        private TextView textViewPhone;

        public ListItemHolder(View itemView) {
            super(itemView);
            textViewName = itemView.findViewById(R.id.textViewName);
            textViewPhone = itemView.findViewById(R.id.textViewPhone);
            textViewName.setOnClickListener(this);
        }

        @Override
        public void onClick(View view) {
            if (mListener != null) {
                mListener.onContactClick(getAdapterPosition());
            }
        }
    }
}
