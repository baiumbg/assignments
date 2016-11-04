import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Driver {
    public static void PrintMenu() {
        System.out.println("Choose an option:\n");
        System.out.println("1. All tasks ordered by priority");
        System.out.println("2. All tasks marked as IN PROCESS");
        System.out.println("3. All tasks with a deadline within 3 days");
        System.out.println("4. Exit\n");
        System.out.print("Your choice (1-4): ");
    }

    public static int ReadChoice() {
        int choice = 0;
        Scanner scanner = new Scanner(System.in);
        try {
            PrintMenu();
            choice = scanner.nextInt();
            if(choice < 1 || choice > 4) {
                throw new IOException("InvalidChoice");
            }
        }
        catch (InputMismatchException | IOException ex) {
            System.out.println("Invalid choice!");
            return ReadChoice();
        }
        return choice;
    }

    public static void main(String[] args) {
        TODOList list = new TODOList();
        list.addTask(new Task("Fix product packaging", "Packaging script is currently borked; pls fix", Task.TaskStatus.INITIAL, 2, "11.11.2016"));
        list.addTask(new Task("Fix crash in rendering", "Renderer crashes on page load; test with attached page", Task.TaskStatus.IN_PROCESS, 1, "14.11.2016"));
        list.addTask(new Task("Discuss product pricing", "", Task.TaskStatus.INITIAL, 3, "9.11.2016"));
        list.addTask(new Task("Add trial expiration", "Create, discuss and implement trial expiration for new product", Task.TaskStatus.IN_PROCESS, 1, "21.11.2016"));
        list.addTask(new Task("Task 5", "Too lazy to think of any more tasks", Task.TaskStatus.DONE, 4, "02.11.2016"));
        list.addTask(new Task("Task 6", "Too lazy to think of any more tasks", Task.TaskStatus.IN_PROCESS, 5, "08.11.2016"));
        list.addTask(new Task("Task 7", "Too lazy to think of any more tasks", Task.TaskStatus.IN_PROCESS, 2, "10.11.2016"));
        list.addTask(new Task("Task 8", "Too lazy to think of any more tasks", Task.TaskStatus.INITIAL, 1, "13.11.2016"));
        list.addTask(new Task("Task 9", "Too lazy to think of any more tasks", Task.TaskStatus.DONE, 5, "05.11.2016"));
        list.addTask(new Task("Task 10", "Too lazy to think of any more tasks", Task.TaskStatus.IN_PROCESS, 3, "17.11.2016"));
        int choice;
        do {
        choice = ReadChoice();
            switch (choice) {
                case 1:
                    list.printByPriority();
                    break;
                case 2:
                    list.printInProgress();
                    break;
                case 3:
                    list.printCloseToDeadline();
                    break;
            }
        } while(choice != 4);
    }
}