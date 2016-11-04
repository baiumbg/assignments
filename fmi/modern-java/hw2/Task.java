import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Task implements Comparable<Task> {
    public enum TaskStatus {
        INITIAL("INITIAL"),
        IN_PROCESS("IN PROCESS"),
        DONE("DONE");

        TaskStatus(String status) {
            this.value = status;
        }

        @Override
        public String toString() {
            return value;
        }

        private final String value;
    }

    public static SimpleDateFormat dateFormat = new SimpleDateFormat("dd.MM.yyyy");

    Task(String title, String description, TaskStatus status, int priority, String deadline) {
        this.title       = title;
        this.description = description;
        this.status      = status;
        this.priority    = priority;

        try {
            this.deadline = dateFormat.parse(deadline);
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public TaskStatus getStatus() {
        return status;
    }

    public int getPriority() {
        return priority;
    }

    public Date getDate() {
        return deadline;
    }

    @Override
    public int compareTo(Task otherTask){
        if (this.priority < otherTask.priority) {
            return -1;
        }
        else if (this.priority > otherTask.priority) {
            return 1;
        }
        else {
            return 0;
        }
    }

    @Override
    public String toString() {
        return "Title: "        + this.title                            + "\n" +
                "Description: " + this.description                      + "\n" +
                "Status: "      + this.status                           + "\n" +
                "Deadline: "    + dateFormat.format(this.deadline)      + "\n" +
                "Priority: "    + this.priority                         + "\n";
    }

    private String                 title;
    private String                 description;
    private TaskStatus             status;
    private int                    priority;
    private Date                   deadline;
}
