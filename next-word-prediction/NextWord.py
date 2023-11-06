import tensorflow as tf
from tensorflow.keras.layers import Embedding, LSTM, Dense
from tensorflow.keras.models import Sequential
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences
import numpy as np
import os
os.environ["CUDA_VISIBLE_DEVICES"] = "-1"

# Load and preprocess the data
with open("shackspere") as file:
    data = file.read()
corpus = data.lower().split("\n")
tokenizer = Tokenizer()
tokenizer.fit_on_texts(corpus)
total_words = len(tokenizer.word_index) + 1
input_sequences = []
for line in corpus:
    token_list = tokenizer.texts_to_sequences([line])[0]
    for i in range(1, len(token_list)):
        n_gram_sequence = token_list[:i+1]
        input_sequences.append(n_gram_sequence)
max_sequence_len = max([len(seq) for seq in input_sequences])
padded_input_sequences = np.array(pad_sequences(input_sequences, maxlen=max_sequence_len, padding='pre'))

# Create input and output sequences for training
x, y = padded_input_sequences[:,:-1], padded_input_sequences[:,-1]
y = tf.keras.utils.to_categorical(y, num_classes=total_words)

# Build the model
model = Sequential()
model.add(Embedding(total_words, 100, input_length=max_sequence_len-1))
model.add(LSTM(150))
model.add(Dense(total_words, activation='softmax'))

# Compile and train the model
model.compile(loss='categorical_crossentropy', optimizer='adam')
model.fit(x, y, batch_size=20, epochs=20)

# Define a function to generate responses to user input
def generate_response(user_input):
    # Convert the user input to a sequence
    sequence = tokenizer.texts_to_sequences([user_input])[0]
    # Pad the sequence
    padded_sequence = pad_sequences([sequence], maxlen=max_sequence_length, padding="pre")
    # Predict the next word using the trained model
    prediction = model.predict(padded_sequence)[0]
    # Get the index of the predicted word
    predicted_index = tf.argmax(prediction).numpy()
    # Convert the index to the predicted word
    predicted_word = tokenizer.index_word[predicted_index]
    return predicted_word
generate_response("hi there")
