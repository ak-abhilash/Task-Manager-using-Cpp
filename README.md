# Task-Manager-using-Cpp

## Overview:
The C++ Task Manager is a command-line application designed to help users efficiently organize and manage their tasks. It provides a user-friendly interface for adding, editing, categorizing, and tracking tasks, aiding users in prioritizing their workload and staying focused on their goals.

## Key Features:

- **Task Management:** Add tasks with titles, descriptions, due dates, and priorities. Mark tasks as completed, edit task details, and delete tasks as needed.
- **Task Listing:** View all tasks, filter tasks by category, priority, or due date. Display detailed information about each task, including its status.
- **Task Sorting:** Sort tasks based on priority, due date, or completion status. Customize sorting order according to personal preferences.
- **Task Categories:** Organize tasks into categories or projects for better management. Create, edit, and delete categories, and assign tasks to specific categories.
- **User Interface:** Simple and intuitive command-line interface (CLI) with clear menu options and instructions for seamless interaction.
- **Persistence:** Save task data to a file for persistence between application sessions. Robust error handling and data validation ensure data integrity and prevent loss.

## Getting Started:
To use the C++ Task Manager, follow these steps:

   - Clone the repository to your local machine.
  - Compile the source code using a C++ compiler.
 - Run the executable file to start the application.
  - Follow the on-screen instructions to manage your tasks effectively.

## Usage Examples:

  - Add a new task: **addTask** "Title" "Description" "Due Date" "Priority"
  - Mark a task as completed: completeTask <taskID>
  - View all tasks: **viewTasks**
  - Filter tasks by category: viewTasksByCategory "Category"
  - Sort tasks by due date: sortTasksByDueDate
  - Create a new category: createCategory "CategoryName"
  - Assign a task to a category: assignTaskToCategory <taskID> "Category"

## Contributing:
Contributions to the C++ Task Manager project are welcome! If you have suggestions for improvements or would like to report a bug, please submit an issue on GitHub. You can also fork the repository, make your changes, and submit a pull request for review.

## License:
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements:
Thank you to all contributors who have helped improve the C++ Task Manager project. Your contributions are greatly appreciated!
