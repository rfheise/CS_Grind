import os
import csv

from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker

engine = create_engine(os.getenv("DATABASE_URL"))
db = scoped_session(sessionmaker(bind=engine))

def main():
    dumb = db.execute("SELECT * FROM books WHERE ibsn = '0752852612'").fetchone()
    if not dumb:
        print("Dumbo")
    else:
        print(f"id:{dumb.id},title:{dumb.title},ibsn:{dumb.ibsn}")



if __name__ == "__main__":
    main()
