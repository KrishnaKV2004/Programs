import os
import pandas as pd
from reportlab.lib.pagesizes import letter
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle

def convert_excel_to_pdf(folder_path):
    # List all files in the folder
    files = os.listdir("D:/Excel")

    # Filter Excel files
    excel_files = [file for file in files if file.endswith('.xlsx') or file.endswith('.xls')]

    # Create a PDF for each Excel file
    for excel_file in excel_files:
        excel_path = os.path.join(folder_path, excel_file)
        df = pd.read_excel(excel_path)

        # Create PDF with ReportLab
        pdf_name = excel_file.replace('.xlsx', '.pdf')
        pdf_path = os.path.join(folder_path, pdf_name)

        doc = SimpleDocTemplate(pdf_path, pagesize=letter)
        elements = []

        # Convert DataFrame to a list of lists for the table
        data = df.values.tolist()
        table = Table(data)

        # Add style to the table
        style = TableStyle([('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                            ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                            ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                            ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                            ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                            ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                            ('GRID', (0, 0), (-1, -1), 1, colors.black)])

        table.setStyle(style)
        elements.append(table)

        # Build the PDF file
        doc.build(elements)

        print(f"Converted {excel_file} to {pdf_name}")

if __name__ == "__main__":
    folder_path = "path/to/your/excel/files/folder"
    convert_excel_to_pdf(folder_path)
