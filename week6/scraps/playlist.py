import cs50
import csv

def main():
    min_tempo = cs50.get_int("Minimum tempo: ")
    max_tempo = cs50.get_int("Maximum tempo: ")

    playlist = []
    # TODO: Read songs from 2018_top100.csv into playlist
    # using 'with open' ensures that the file is auto closed after completion
    with open("2018_top100.csv") as file:
        reader = csv.DictReader(file)
        for row in reader:
            if min_tempo < float (row["tempo"]) < max_tempo:
                playlist.append(row)

    # TODO: Print song titles from playlist
    for song in playlist:
        print(song["name"], song["tempo"])
        

main()
