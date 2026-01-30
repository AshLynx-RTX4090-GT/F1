           printf("Enter the value to be inserted : ");
            scanf("%d", &info);
            if (search(root, info) == NULL)
                root = insert(info, root, &ht_inc);
            else
                printf("Duplicate value ignored\n");
            break;
        case 2:
            if (root == NULL) {
                printf("Tree is empty\n");
                continue;
            }
            printf("Tree is :\n");
            display(root, 1);
            printf("\n\n");
            printf("Inorder Traversal is: ");
            inorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}